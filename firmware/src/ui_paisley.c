/* SPDX-License-Identifier: GPL-3.0-only
 * Paisley HOME: an additional, non-destructive navigation view for Melodee.
 * The source UI remains available on its Stage and chord HOME views.
 * Copyright (C) 2026 Paisley contributors
 */

/* No independent framebuffer: render using Melodee's existing bounded canvas.
 * The backdrop is a static forest motif for this milestone. Living-forest
 * animation and sound-reactive elements are deliberately out of scope. */
static const char *const PAISLEY_TILE_NAME[PAISLEY_TILES] = {
    "STUDIO", "SYNTH", "MIXER", "MIDI", "PROJECT", "SETTINGS"
};

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

        /* Soft treeline and ground: low contrast behind opaque navigation tiles. */
        cv_rect(0, 151, 240, 59, mist);
        for (k = 0; k < 10u; k++) {
            int32_t cx = 9 + (int32_t)k * 25;
            int32_t top = 122 + (int32_t)(k * 13u % 28u);
            cv_rect(cx, top, 3, 208 - top, trees);
            cv_line(cx - 10, top + 18, cx + 1, top, foliage);
            cv_line(cx + 1, top, cx + 12, top + 18, foliage);
            cv_line(cx - 8, top + 28, cx + 1, top + 7, foliage);
            cv_line(cx + 1, top + 7, cx + 10, top + 28, foliage);
        }
        /* Firefly-like points are static until the later Living Forest milestone. */
        cv_rect(14, 120, 2, 2, T_ACCENT);
        cv_rect(219, 137, 2, 2, T_THEME);
        cv_rect(75, 145, 2, 2, T_ACCENT);

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
