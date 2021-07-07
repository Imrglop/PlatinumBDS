# Platinum

Platinum is a Bedrock Dedicated Server mod for enhancements and more customization. 

## Installation

1. Make sure you have a dll injector like [Element Minus](https://github.com/karikera/elementminus)
2. Go to a release (or build it yourself) and get the DLL and the Platinum directory installed
3. Place dll in a mods directory (or however way you inject the DLL)
4. Place the Platinum directory in the main BDS folder. Make sure it has all the files like:
- `sigcache.txt`
- `settings.txt`
- etc.

## Version

Supports BDS **1.17.2**

## Usage

*If you are using a legacy BDS version (1.16.20 - 1.16.201)*

- Go to `settings.txt` and turn on `legacy-bds-version`. Not all versions support all modules. However, the latest version always has all the modules working.

**In settings.txt:**
`mod-enabled` is whether Platinum will load modules to modify the BDS. Only certain modules that you enable will be enabled.

If you scroll down to the modules section, each module has a `module-name:module-setting` format. Each module has a setting named `enabled` which indicates whether Platinum will enable this module or not.

## Features

### Knockback Edit

With this module, you can edit the horizontal and vertical knockback.

**Use Legacy Knockback** (use-legacy-knockback) If enabled, BDS will use 1.12 and below knockback. This allows for more dynamic knockback.

*Is Editing Knockback* (is-editing-knockback) If enabled, you'll be able to modify knockback values below.

*Is Offset* (is-offset) If enabled, the knockback values below will be added (+) to the vanilla values.

**Vertical Knockback** (vertical-knockback) The modifier for +Y (or -Y, if you run *that* type of server) knockback

**Horizontal Knockback** (horizontal-knockback) The modifier for +X and +Z (or -X and -Z) knockback

### HurtTime Edit

**Hurt Time** (hurt-time) Delay between hits in each entity

### Seed Hider

If enabled, hides the seed from the Game settings menu for players.

### Basic Anti Cheat

**Anti Spawn Experience Orb** (anti-spawn-experience-orb) Whether BDS will now block requests to spawn an experience orb on their location, found in cheat clients.

## License

MIT License (Some source files, like libraries such as [MinHook](https://github.com/TsudaKageyu/minhook) are not protected by this license)