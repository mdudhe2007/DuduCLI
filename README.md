<div align="center">

```
██████╗ ██╗   ██╗██████╗ ██╗   ██╗ ██████╗██╗     ██╗
██╔══██╗██║   ██║██╔══██╗██║   ██║██╔════╝██║     ██║
██║  ██║██║   ██║██║  ██║██║   ██║██║     ██║     ██║
██║  ██║██║   ██║██║  ██║██║   ██║██║     ██║     ██║
██████╔╝╚██████╔╝██████╔╝╚██████╔╝╚██████╗███████╗██║
╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝  ╚═════╝╚══════╝╚═╝
```

**A fake Linux-style terminal simulator written in C++.**  
_Type commands. Break things. Learn systems programming._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Linux-green.svg)](https://kernel.org/)
[![Build](https://img.shields.io/badge/Build-g%2B%2B-orange.svg)](https://gcc.gnu.org/)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)]()
[![Purpose](https://img.shields.io/badge/Purpose-Educational-purple.svg)]()

</div>

---

## 📖 About

**DuduCLI** is a terminal emulator written entirely in C++ that simulates a Linux-style shell environment. It mimics the look and feel of a real Unix shell — with an in-memory filesystem, command history, file I/O simulation, and passthrough to real Linux tools — all from a single lightweight header.

This project was built as a **beginner systems programming exercise** to explore:
- How shells parse and dispatch commands
- How filesystems can be modeled in memory
- How C++ standard containers can back a stateful application

> ⚠️ **Educational Project** — DuduCLI is designed for learning purposes. It is not a production shell and does not interface with the real filesystem (except for passthrough commands like `btop` and `cmatrix`).

---

## ✨ Features

### 🗂️ Built-in Commands

| Command    | Description                                      |
|------------|--------------------------------------------------|
| `echo`     | Print text to the terminal                       |
| `nano`     | Write and save a file to the in-memory filesystem|
| `cat`      | Display the contents of an in-memory file        |
| `ls`       | List all in-memory directories and files         |
| `mkdir`    | Create a new directory in memory                 |
| `rmdir`    | Remove a directory from memory                   |
| `cd`       | Simulate changing directory                      |
| `clear`    | Clear the terminal screen                        |
| `history`  | Display all previously entered commands          |
| `version`  | Show DuduCLI version                             |
| `--help`   | Show all available commands                      |
| `exit`     | Quit the shell                                   |

### 🚀 External Command Passthroughs

These commands call real Linux tools installed on your system:

| Command      | Description                          |
|--------------|--------------------------------------|
| `btop`       | Interactive process/resource monitor |
| `fastfetch`  | System information display           |
| `cmatrix`    | The Matrix raining code effect 🟩    |
| `ip`         | Show network interface information   |

### 🧠 Core Internals

- **In-memory filesystem** — directories and files backed by `std::vector`
- **Command history** — every command logged and retrievable
- **Single-header design** — the entire shell lives in `duduboiii.h`
- **Simple command parser** — splits input into `cmd` and `args`

---

## 📁 Project Structure

```
DuduCLI/
│
├── duduboiii.h        # Core shell logic — all commands implemented here
├── main.cpp           # Entry point — REPL loop and input parsing
├── README.md          # You are here
└── LICENSE            # MIT License
```

---

## ⚙️ Installation

### Prerequisites

- Linux (Ubuntu, Arch, Debian, etc.)
- `g++` with C++17 support
- Optional: `btop`, `fastfetch`, `cmatrix` for passthrough commands

**Install optional dependencies:**
```bash
# Ubuntu / Debian
sudo apt install btop cmatrix

# Arch
sudo pacman -S btop cmatrix

# fastfetch (from GitHub releases or AUR)
sudo apt install fastfetch   # Ubuntu 24.04+
```

### Clone the Repository

```bash
git clone https://github.com/mdudhe2007/DuduCLI.git
cd DuduCLI
```

---

## 🔨 Compilation

```bash
g++ -std=c++17 main.cpp -o dudushell
```

Then run it:

```bash
./dudushell
```

---

## 💻 Usage

Once running, you'll see the DuduCLI prompt:

```
>
```

Type any supported command and press Enter.

### Example Session

```bash
> version
DuduCLI v69.69

> echo Hello, World!
Hello, World!

> mkdir projects
Directory created: projects

> mkdir src
Directory created: src

> ls
Directories:
projects
src

Files:

> nano notes.txt
Write content: This is my first DuduCLI file!
File saved

> cat notes.txt
This is my first DuduCLI file!

> ls
Directories:
projects
src

Files:
notes.txt

> History
echo Hello, World!
mkdir projects
mkdir src
ls
nano notes.txt
cat notes.txt
ls

> clear

> exit
Exiting...
```

---

## 🖼️ Screenshots

> _Screenshots coming soon!_





---

## 🏗️ How It Works

DuduCLI's architecture is intentionally minimal:

```
main.cpp                      duduboiii.h
┌──────────────────┐          ┌──────────────────────────────┐
│  while (true)    │          │  Global State:               │
│    read cmd+args │─────────▶│    vector<string> dir        │
│    call shell()  │          │    vector<vector> files      │
│    check exit    │          │    vector<vector> history    │
└──────────────────┘          │                              │
                              │  shell(cmd, args):           │
                              │    log to history            │
                              │    if/else dispatch          │
                              │    execute command           │
                              └──────────────────────────────┘
```

1. `main.cpp` runs a **REPL loop** (Read → Evaluate → Print → Loop)
2. Input is split into a command and an argument string
3. `shell()` in `duduboiii.h` logs the call and dispatches to the right handler
4. State (files, directories, history) persists across commands for the session

---

## 🔮 Future Improvements

Here's what could make DuduCLI even better:

- [ ] **Persistent filesystem** — save/load files to disk between sessions
- [ ] **Piping support** — chain commands with `|`
- [ ] **Redirection** — support `>` and `>>` for output to files
- [ ] **Tab completion** — autocomplete commands as you type
- [ ] **Colored output** — ANSI color codes for a richer terminal experience
- [ ] **Environment variables** — support `$VAR` style variables
- [ ] **Script execution** — run `.dsh` script files
- [ ] **Real `cd`** — actually change the working directory
- [ ] **Fix `history` capitalization** — make it case-insensitive
- [ ] **`rm` command** — delete in-memory files
- [ ] **`mv` / `cp`** — move and copy files in memory
- [ ] **`pwd`** — print the current (simulated) working directory

---

## 🤝 Contributing

Contributions are welcome! This is a learning project, so all skill levels are encouraged.

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/new-command`
3. Commit your changes: `git commit -m "Add: new-command support"`
4. Push to the branch: `git push origin feature/new-command`
5. Open a Pull Request

Please keep code simple and well-commented — this project is meant to be readable by beginners.

---

## 📜 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

Free to use, modify, and distribute. If it helped you learn something, that's all that matters. ⭐

---

## 👤 Author

**Your Name**  
GitHub: [@mdudhe2007](https://github.com/mdudhe2007)

---
Contributors

<a href="https://github.com/mdudhe2007/DuduCLI/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=mdudhe2007/DuduCLI" />

--- 

</a><p>Thanks to all contributors who have helped improve DuduCLI! 🎉</p>

<div align="center">

_Built for learning. Inspired by Linux. Powered by curiosity._

⭐ **Star this repo if it helped you learn something new!** ⭐

</div>
