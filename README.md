# Sentinel LKM Blackbox Kernel

A Linux kernel module project to monitor process activity, designed for experimentation and learning with kernel modules. This repository contains a simple "process monitor" kernel module that prints information about the currently executing process.

---

## 📁 Folder Structure
```
Sentinel-LKM-Blackbox-Kernel/
├── kernel/
│ └── procmon/
│ ├── procmon.c # Kernel module source code
│ ├── Makefile # Makefile to build the module
│ ├── .gitignore # Ignored files (e.g., *.ko, *.o, Module.symvers)
│ ├── Module.symvers # Auto-generated (ignored in git)
│ ├── procmon.ko # Compiled kernel module (ignored in git)
│ ├── procmon.o # Object file (ignored in git)
│ └── ... # Any other generated module files
├── README.md # This file
└── .gitignore # Repo-wide ignored files
```

---

## ⚙️ Requirements

- Linux kernel headers installed (matching your running kernel).
- `gcc` compiler compatible with the kernel version.
- Root permissions to load/unload kernel modules.
- Make sure `make` is installed.

On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
```
🛠 Building the Module

1)Navigate to the kernel module directory:
```
cd kernel/procmon
```
2)Clean any previous builds:
```
make clean
```
3)Build the kernel module:
```
make
```
If the build succeeds, you’ll get procmon.ko.

🚀 Using the Kernel Module:
1)Insert the module:
```
sudo insmod procmon.ko
```
2)Check the kernel log to see what the module prints:
```
sudo dmesg | tail -n 20
```
3)Remove the module when done:
```
sudo rmmod procmon
```
4)Confirm removal:
```
sudo dmesg | tail -n 20
```
📝 Notes

This module prints information about the currently executing process at the time of insertion.

Only compatible with kernels that support the tracepoints used in procmon.c.

Generated files like .ko, .o, Module.symvers, and *.mod.c are ignored in git via .gitignore.

Keep this repo clean by committing only source files and .gitignore.

📜 Git Workflow
1)📜 Git Workflow:
```
git add <file>
```
2)Commit with clear messages:
```
git commit -m "feat(procmon): added XYZ"
```
3)Push to GitHub:
```
git push -u origin main
```
For kernel modules, do not commit compiled .ko files.

⚡ Example Output
After inserting the module:
```yaml
[ 1234.567890] procinfo: module loaded
[ 1234.567891] procinfo: current process is insmod[5678]
[ 1234.567892] procinfo: PID: 5678 | Name: insmod
```
🧰 License:

This project is released under the MIT License.
