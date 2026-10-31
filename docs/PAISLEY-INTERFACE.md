# Paisley Interface Architecture

## Design philosophy

**The look of BaudGirl. The musical power of Melodee. The atmosphere of a living forest.**

Paisley is a custom Melodee-based firmware for the M-VAVE FM-1. It retains Melodee's musical depth, engines, sequencing and sound-design capabilities while introducing a new identity, interface and workflow.

The visual inspiration is the purple version of BaudGirl firmware, combined with the calm, organic atmosphere of Zen-1.

Paisley should feel like a musical instrument with its own personality.

## 1. New Paisley HOME screen

The HOME screen is the first screen displayed when Paisley starts.

### Branding and visual design
- Prominent PAISLEY name and identity.
- Purple-themed default visual palette inspired by BaudGirl.
- Dark backgrounds with carefully selected purple tones, highlights and accents.
- Cohesive typography, graphics, borders and interface elements.
- Original Paisley identity rather than a direct copy of another firmware.
- Clear, readable information and intuitive navigation.

### HOME screen navigation

Direct access to:
- STUDIO: Tracks, patterns, sequencing and song arrangement.
- SYNTH: Instrument selection, presets and sound design.
- MIXER: Track levels, panning and audio balance.
- MIDI: MIDI configuration, routing and sequencing.
- PROJECT: Save, load and manage projects.
- SETTINGS: Global configuration, themes and system preferences.

The HOME screen must be a genuine new interface, not simply a renamed Melodee screen.

## 2. Theme customization

Paisley must include a customizable firmware-wide color system inspired by BaudGirl's theme customization.

### Built-in themes

Initial theme presets:
1. Paisley Purple — default purple identity.
2. Forest — natural greens and earthy accents.
3. Midnight — deep dark tones with cool highlights.
4. Ocean — blue and turquoise tones.
5. Amber — warm gold and orange tones.
6. Rose — pink and magenta tones.

### Custom theme editor

Allow the user to customize:
- Primary background color.
- Secondary background and panel color.
- Primary accent color.
- Secondary accent color.
- Highlight and selection color.
- Primary text color.
- Secondary text color.
- Borders and separators.

### Theme behavior
- Provide an immediate visual preview while adjusting colors.
- Allow custom themes to be named and saved.
- Allow switching between saved themes.
- Include a restore-defaults option.
- Retain the selected theme after power cycling.
- Apply themes consistently across HOME, STUDIO, SYNTH, MIXER, MIDI, PROJECT and SETTINGS.
- Maintain readable contrast and legibility.
- Ensure colors remain distinguishable on the FM-1 display.
- Avoid excessive memory use and unnecessary rendering overhead.

Theme customization should change the visual appearance only. It must never alter synthesis, sequencing, presets or project data.

### Living Forest integration

The Living Forest retains its own natural environmental palette.

The selected firmware theme may subtly influence ambient lighting, highlights and atmospheric accents, without recoloring the entire forest or compromising its natural appearance.

## 3. STUDIO

The musical workspace.

Preserve Melodee's existing capabilities:
- Multitrack sequencing.
- Track selection and management.
- Pattern creation and editing.
- Song arrangement.
- Recording and playback.
- MIDI sequencing and routing.
- Track volume and panning.
- Automation and modulation.
- Project saving and loading.

Visual design:
- Follow the selected Paisley theme.
- Prioritize clarity and efficient operation.
- Keep sequencing information easy to read.
- Use subtle visual elements rather than distracting animations.

## 4. SYNTH

The sound-design workspace.

Preserve Melodee's existing sound engines and advanced sound-design capabilities.

Primary functions:
- Instrument and engine selection.
- Preset browsing.
- Basic and Advanced sound-design modes.
- Sound macros.
- Envelopes.
- LFO and modulation.
- Effects and routing.
- Voice and performance settings.

Visual design:
- Follow the selected Paisley theme.
- Include the interactive Living Forest visualizer.
- Provide clear parameter feedback.
- Keep sound-shaping functions accessible.

## 5. Basic and Advanced modes

Basic mode provides seven musical macros:

1. Character
2. Brightness
3. Warmth
4. Movement
5. Space
6. Attack
7. Release

Advanced mode exposes the selected engine's native parameters and modulation controls.

Switching between modes must be nondestructive. Basic mode must not overwrite or discard native engine settings.

## 6. The Living Forest

The Living Forest is Paisley's signature visual experience within the SYNTH environment.

It should feel like a peaceful, mysterious woodland that gradually comes alive as the musician explores sounds.

### Visual style
- Atmospheric pixel-art or lightweight layered 2D graphics.
- Deep purple twilight tones, muted greens and soft natural highlights.
- Organic shapes, moss, trees, grass, water and subtle environmental depth.
- Soft bioluminescence rather than harsh neon.
- Gentle movement and smooth transitions.
- No distracting constant animation.
- Optional static or reduced-motion mode.

### Growing mushrooms

Mushrooms should gradually appear and grow throughout the forest as the musician explores and changes sounds.

Behavior:
- Small mushrooms can emerge near moss, tree roots and fallen logs.
- Mushrooms grow slowly rather than appearing instantly.
- Different sound-design interactions can encourage different mushroom varieties.
- Some mushrooms can have subtle bioluminescent caps.
- Mature mushrooms remain in the environment, creating a sense of gradual development.
- The forest should have a reasonable limit on the number of mushrooms to preserve visual clarity and hardware resources.

Mushroom growth should feel like a reward for exploration, not a score or achievement system.

### Fireflies

Fireflies should appear when sound parameters are changed.

Behavior:
- Changing a parameter can release a small number of fireflies into the environment.
- Larger or more meaningful parameter changes can create a slightly more noticeable response.
- Fireflies drift gently around the forest.
- Their glow should be soft, warm and organic.
- They gradually fade or disappear.
- Multiple parameter changes should not create overwhelming visual activity.
- Fireflies can occasionally gather around mushrooms or illuminated areas.

A single knob adjustment should not trigger an explosion of visual effects.

### Musical and parameter interaction

The forest should respond to both sound-design activity and musical events.

Parameter relationships:
- Character: influences vegetation and overall environmental character.
- Brightness: influences sunlight and highlights.
- Warmth: influences color temperature and foliage.
- Movement: influences wind, grass and leaves.
- Space: influences mist, depth and distance.
- Attack: influences how quickly visual responses emerge.
- Release: influences how slowly visual responses fade.

Musical reactions:
- Individual notes trigger subtle light or environmental responses.
- Chords create broader visual changes.
- Bass notes influence ground and water movement.
- Sustained pads gradually change the atmosphere.
- Silence allows the scene to settle.

### A sense of continuity

The forest should feel as though it is gradually developing rather than resetting after every interaction.

- Preserve the visual state during normal navigation between SYNTH pages.
- Allow mushroom growth to accumulate gradually.
- Avoid excessive random effects.
- Use deterministic, lightweight visual rules where practical.
- Do not let visual effects interrupt sound editing or sequencing.

The visualizer must run independently of the audio-processing thread. It must never compromise real-time audio performance.

## 7. Architecture and compatibility

- Preserve Melodee's existing audio engines.
- Preserve the multitrack sequencer and song arrangement.
- Preserve independent track instruments, presets, effects, levels, panning and automation.
- Preserve existing MIDI functionality.
- Preserve project and preset compatibility wherever possible.
- Keep interface navigation separate from sound-engine and sequencer state.
- Store global theme preferences independently of musical project data.
- Avoid unnecessary changes to the audio engine.
- Maintain firmware resource limits and real-time audio stability.

## 8. Development sequence

1. Create the new Paisley startup identity and purple HOME screen.
2. Implement HOME navigation to STUDIO, SYNTH, MIXER, MIDI, PROJECT and SETTINGS.
3. Implement the firmware theme system and custom theme editor.
4. Preserve and verify all existing Melodee functions.
5. Implement Basic and Advanced synth modes.
6. Implement MiniLab 3 control integration.
7. Implement Scale Guide and Scale Lock.
8. Improve live note and chord recognition.
9. Develop the Living Forest base environment.
10. Add gradual mushroom growth and parameter-responsive fireflies.
11. Integrate musical reactions and visual parameter mappings.

Every change must pass the automated build and relevant tests before browser-emulator testing. Physical FM-1 installation requires separate hardware validation and a verified recovery plan.
