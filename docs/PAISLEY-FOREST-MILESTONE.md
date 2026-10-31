# Paisley Living Forest — visual foundation (Milestone 2A)

This change refines the Paisley HOME scene only. Its forest floor has moss, roots,
seven tiny mushroom clusters, and five firefly points. Selecting another HOME tile
moves the firefly constellation. The art uses theme tokens and the existing
band-limited canvas; it does not allocate memory, create timers, access audio,
or modify project/patch data.

It does **not** yet implement time-based animation, progressive mushroom growth,
synth parameter mapping, reduced-motion preferences or custom editable theme
colors. Those require distinct UI/event/configuration work and hardware budget
verification. The original Melodee palette selection remains available.

Tested locally: generated headers, compiled and ran `tests/ui_test.c` (all passed),
and compiled and ran `tests/ui_render.c` (0 layout findings, 0 MONO off-gray
pixels). The full firmware/toolchain build and complete host regression suite
must still pass in GitHub Actions before claiming firmware validation.
