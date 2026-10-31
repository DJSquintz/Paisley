# Paisley HOME — milestone 1

This change adds **HOME view 2** (the Paisley six-tile landing screen) while retaining Melodee's Stage (view 0), chord view (view 1), audio engines, sequencer, persistence and existing pages. The boot-time start image says PAISLEY. There are no firmware-format changes.

## Controls

- On a fresh boot, HOME shows Paisley's six-tile dashboard.
- Turn **SELECT** to move between the six tiles, wrapping at either end.
- Tap **OCT+** to open the selected destination.
- Tap **OCT-** to leave the dashboard for the original Stage without changing octave.
- Tap **HOME** to cycle dashboard → Stage → chord view → dashboard (repeat). HOME held still opens the original settings menu.
- HOME from a functional page returns to the most recently viewed HOME screen, as in Melodee.
- PLAY, REC, sequencer and track page buttons keep Melodee's original behavior.

## Destinations

| Tile | Existing Melodee destination |
|---|---|
| STUDIO | SEQ family (NOTES by default) |
| SYNTH | EDIT family (last EDIT page) |
| MIXER | MIXER, track level/pan/mute |
| MIDI | SYSTEM, MIDI configuration and routing |
| PROJECT | PROJECT slot save/load management |
| SETTINGS | HOME-held device preferences menu |

## Scope

- The backdrop is a low-cost **static** purple/forest motif, not the later sound-reactive Living Forest.
- The pre-existing `PAISLEY` palette is preserved. The default palette remains Melodee's NIGHT for compatibility; to use Paisley Purple choose **HOME held → COLOR → PAISLEY**. This milestone does *not* add per-theme customization or a palette migration.
- The dashboard redraws only when UI state forces a refresh; the transport header stays live.
- No change to firmware image format, audio engine, sequencer, projects or save slots.

## Validation in preparation environment

- `tests/ui_test.c` compiled and passed, including all six tile destinations and no accidental patch changes from dashboard controls.
- `tests/theme_test.c` passed contrast, palette order and typography assertions.
- `tests/ui_render.c` passed with zero layout findings and zero pixels breaking gray mode; six dashboard focus positions were rendered under every palette.
- Dashboard screenshot was bit-identical between the normal banded canvas and a larger reference canvas.
- The full firmware, complete GitHub Actions suite, browser emulator and **hardware installation are not validated by these local checks**. Run the existing Paisley GitHub Actions workflow on `paisley-home-screen` before attempting any device test.
