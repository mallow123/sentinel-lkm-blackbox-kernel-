# Sentinel LKM: BlackBox Kernel Module

[![License](https://img.shields.io/badge/License-GPLv2-green)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C-blue)](https://www.kernel.org/)
[![Repo Size](https://img.shields.io/github/repo-size/mallow123/sentinel-lkm-blackbox-kernel-)](https://github.com/mallow123/sentinel-lkm-blackbox-kernel-)
[![GitHub stars](https://img.shields.io/github/stars/mallow123/sentinel-lkm-blackbox-kernel-?style=social)](https://github.com/mallow123/sentinel-lkm-blackbox-kernel-/stargazers)


**Sentinel BlackBox** is a Linux kernel module framework for advanced system introspection, monitoring, and experimentation with kernel-level modules. This repository currently contains a **Hello World kernel module** as a foundation for future modules like process monitors, filesystem interceptors, and network hooks.

---

## 🔍 Features (Current & Planned)

- **Current Module**
  - `hello_world.c`: Basic kernel module printing logs on insertion and removal.
- **Planned Modules**
  - Process Monitoring (`procmon`)
  - Filesystem Interception (`fsint`)
  - Network Hooks (`netmon`)
  - Utility helpers (`utils`)

---

## 📂 Project Structure
```
blackbox-kernel/
├── README.md
├── LICENSE
├── .gitignore
├── kernel/
│   ├── include/
│   ├── utils/
│   ├── procmon/
│   │   ├── hello_world.c
│   │   └── Makefile
│   ├── fsint/
│   └── netmon/
├── userspace/
│   ├── cli/
│   └── tui/
├── tools/
│   ├── scripts/
│   └── analyzers/
└── tests/
    ├── kunit/
    └── fuzz/
```
---
## 🔭 Current Focus
- Expanding `procmon` to log process activity
- Building filesystem interception (`fsint`) module
- Network hooks (`netmon`) for packet analysis
- Developing userspace TUI interface for real-time visualization
## 🛠️ Build & Setup

### Requirements
- Linux system (Ubuntu recommended)
- `make`, `gcc`
- Kernel headers for your current kernel:
```bash
sudo apt install build-essential linux-headers-$(uname -r)
```
  
## Compile Kernel Module
```
cd ~/Desktop/blackbox-kernel/kernel/procmon
make
```
## This generates hello_world.ko.
---
## Load Module
```
sudo insmod hello_world.ko
lsmod | grep hello_world
sudo dmesg | tail
```
## Remove Module
```
sudo rmmod hello_world
sudo dmesg | tail
```

## ⚠️ Notes
Secure Boot must be disabled to load unsigned modules.

Custom kernel modules taint the kernel, which is expected for out-of-tree modules.
  
## 🤝 Contributing
- Feel free to fork the repo and experiment.
- Please do **not use this for malicious purposes**.
- Only push signed or test modules to your own systems.


  

