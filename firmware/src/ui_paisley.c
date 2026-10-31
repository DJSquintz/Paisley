/* SPDX-License-Identifier: GPL-3.0-only
 * Paisley HOME: an additional, non-destructive navigation view for Melodee.
 * The source UI remains available on its Stage and chord HOME views.
 * Copyright (C) 2026 Paisley contributors
 */

/* No independent framebuffer: render using Melodee's existing bounded canvas.
 * The forest is deliberately deterministic, with a different cluster of
 * fireflies for each selected tile. No timer, heap use or audio-thread work.
 * Continuous motion and synth-reactivity require separate performance tests. */
static const char *const PAISLEY_TILE_NAME[PAISLEY_TILES] = {
    "STUDIO", "SYNTH", "MIXER", "MIDI", "PROJECT", "SETTINGS"
};

/* Quiet pixel-scale habitat behind the opaque navigation tiles. The renderer
 * clips every primitive to the current canvas band. */
static void paisley_mushroom(int32_t x, int32_t y, uint16_t stem,
                            uint16_t cap, uint16_t glow)
{
    cv_rect(x + 3, y + 4, 3, 6, stem);
    cv_rect(x + 1, y + 2, 7, 3, cap);
    cv_rect(x + 3, y, 3, 2, cap);
    cv_rect(x + 3, y + 2, 1, 1, glow);
    cv_rect(x + 6, y + 3, 1, 1, glow);
}

static void paisley_habitat(uint16_t mist, uint16_t trees, uint16_t foliage)
{
    static const uint8_t mx[] = { 5, 37, 70, 103, 148, 184, 219 };
    static const uint8_t my[] = { 188, 178, 193, 183, 192, 181, 195 };
    uint16_t moss = ux_mix(T_BG, T_ACCENT, 36);
    uint16_t stems = ux_mix(T_TEXT, T_BG, 65);
    uint16_t cap = ux_mix(T_ACCENT, T_THEME, 40);
    uint32_t k;

    cv_rect(0, 151, 240, 59, mist);
    /* Distant trunks and their branches form the deep background. */
    for (k = 0; k < 10u; k++) {
        int32_t cx = 9 + (int32_t)k * 25;
        int32_t top = 122 + (int32_t)(k * 13u % 28u);
        cv_rect(cx, top, 3, 208 - top, trees);
        cv_line(cx - 10, top + 18, cx + 1, top, foliage);
        cv_line(cx + 1, top, cx + 12, top + 18, foliage);
        cv_line(cx - 8, top + 28, cx + 1, top + 7, foliage);
        cv_line(cx + 1, top + 7, cx + 10, top + 28, foliage);
    }
    /* Forest-floor moss, low-contrast roots and little mushroom colonies. */
    cv_rect(0, 202, 240, 8, trees);
    for (k = 0; k < 7u; k++) {
        int32_t x = mx[k], y = my[k];
        cv_line(x - 6, y + 12, x + 15, y + 10, moss);
        paisley_mushroom(x, y, stems, cap, T_THEME);
    }
    /* Selected destination changes the firefly constellation. It is a visual
     * focus cue, not an assertion about current audio or synth parameters. */
    for (k = 0; k < 5u; k++) {
        uint32_t seed = (uint32_t)ui.paisley_tile * 37u + k * 53u;
        int32_t x = 12 + (int32_t)(seed * 17u % 213u);
        int32_t y = 117 + (int32_t)(seed * 11u % 58u);
        cv_rect(x, y, 2, 2, k & 1u ? T_ACCENT : T_THEME);
    }
}

static void paisley_draw(void)
{
    const int32_t cw = 240, ch = 210;
    const int32_t tile_w = 108, tile_h = 42;
    const int32_t tile_x[2] = {8, 124};
    const int32_t tile_y[3] = {57, 108, 159};
    uint16_t mist = ux_mix(T_BG, T_THEME, 14);
    uint16_t trees = ux_mix(T_BG, T_THEME, 22);
    uint16_t foliage = ux_mix(T_BG, T_ACCENT, 24);
    uint32_t band, k;
    const uint32_t strip = CV_MAX / 240u;

    for (band = 0; band < (uint32_t)ch; band += strip) {
        cv_begin_band(cw, (uint32_t)ch, T_BG, band);

        paisley_habitat(mist, trees, foliage);

        cv_text_c(120, ty_y(17, TY_VL), TY_VL, "PAISLEY", T_THEME, T_BG);
        cv_text_c(120, ty_y(45, TY_LB), TY_LB, "SELECT: MOVE  OCT+: OPEN", T_MID, T_BG);

        for (k = 0; k < PAISLEY_TILES; k++) {
            int32_t x = tile_x[k % 2u], y = tile_y[k / 2u];
            int on = (uint32_t)ui.paisley_tile == k;
            uint16_t edge = on ? T_ACCENT : T_LINE;
            uint16_t fill = on ? ux_mix(T_PANEL, T_THEME, 25) : T_PANEL;
            cv_rrect(x, y, tile_w, tile_h, 8, edge, T_BG);
            cv_rrect(x + 2, y + 2, tile_w - 4, tile_h - 4, 6, fill, edge);
            cv_text_c(x + tile_w / 2, ty_y(y + tile_h / 2, TY_LB), TY_LB,
                      PAISLEY_TILE_NAME[k], on ? T_TEXT : T_MID, fill);
            if (on)
                cv_rect(x + 25, y + tile_h - 6, tile_w - 50, 2, T_ACCENT);
        }
        cv_blit_band(0, 30);
    }
    draw_head();
}
