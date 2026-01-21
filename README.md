# AuraOS

**AuraOS** is an independent, Linux-based operating system focused on simplicity, clarity, and full user control.  
It is designed as a modern desktop OS with its **own graphical environment**, **custom userland**, and a clear separation between beginner-friendly and advanced usage.

> AuraOS is not a Linux distribution in the traditional sense — it is a system built *on top of the Linux kernel*, with its own philosophy, tooling, and interface.

## ✨ Goals

- Build a **fully independent OS experience** on the Linux kernel
- Develop a **custom graphical shell and desktop environment**
- Provide a **simple, clean system for regular users**
- Allow **full manual control** for advanced users (similar to Arch philosophy)
- Avoid unnecessary complexity and legacy cruft
- Keep the system transparent and understandable

## 🧠 Philosophy

AuraOS follows a dual-approach philosophy:

### 🟢 For regular users
- Minimal interaction with the terminal
- Simple, clean graphical interface
- Automatic setup of essential software
- App installation via a graphical app store
- One-click actions wherever possible

### 🔵 For advanced users
- Full manual system control
- No forced automation
- Clear and readable configuration
- UNIX philosophy respected
- No hidden magic

The user decides how deep they want to go.

## 🧩 Architecture Overview

### Kernel
- **Linux kernel**, built and configured specifically for AuraOS
- Custom kernel naming and branding
- Minimal, clean configuration focused on desktop use

### Userland
- Custom `init` (`aura-init`)
- Custom shell (`aura-shell`)
- Own basic core utilities (cd, pwd, echo, clear, reboot, poweroff, etc.)
- Busybox-free approach where possible

## 🖥 Graphical Environment (Planned)

AuraOS will feature a **custom-built graphical shell**, not based on GNOME, KDE, or other existing desktop environments.

Planned characteristics:
- Clean, minimal UI
- Focus on usability and responsiveness
- Consistent design language
- Wayland-based (planned)
- Own window manager and compositor
- No forced workflow paradigms

The graphical environment is designed to feel **native to AuraOS**, not a repackaged existing DE.

## 📦 Installation (Planned)

AuraOS will support **two installation modes**:

### Easy Mode
- Graphical installer
- Minimal user input
- Automatic partitioning (optional)
- Preinstalled essential software
- Ready-to-use desktop after installation

### Advanced Mode
- Fully manual installation
- Step-by-step configuration
- No automation
- Complete control over system setup

## 🚧 Project Status

AuraOS is **under active development**.

Current state:
- ✔ Custom kernel build
- ✔ Custom init system
- ✔ Custom shell
- ✔ Basic shell built-in commands
- ✔ Executable userland commands
- 🚧 Expanding core utilities
- 🚧 Improving init and process handling
- 🚧 Graphical environment (early planning)

This project is **not production-ready**.

## 📜 License

AuraOS is licensed under the **AuraOS Non-Commercial License (ANCL)**.

- ✔ Free to use, study, and modify
- ✔ Allowed for educational and personal use
- ❌ Commercial use is forbidden
- ❌ Redistribution under a different name is forbidden
- ❌ Claiming authorship is forbidden

See the `LICENSE` file for full terms.

## 🤝 Contributions

At this stage, AuraOS is primarily a **personal research and development project**.  
Contributions may be considered in the future once the core architecture stabilizes.

## 🌌 Final Notes

AuraOS exists because modern systems are often:
- Overcomplicated
- Bloated
- Detached from the user

This project is an attempt to bring back **clarity, control, and purpose** to a modern desktop operating system.