# SLogger

Lightweight C++17 logging library with ANSI color support.

## Features

- Printf-style and string logging via `Log()`
- Colored output using `ImLogColor` and `ImLogBackGroundColor` enums
- Helper functions: `Info()`, `Warning()`, `Error()`
- Assert support with customizable handler
- Configurable output stream via `API::stream`
- Disable all logging by defining `IMLOG_DISABLE`

## API Overview

| Function | Description |
|---|---|
| `Log(const char* fmt, ...)` | Printf-style formatted log |
| `Log(std::string text)` | String log |
| `Log(ImLogOut& buffer)` | Log from custom output buffer |
| `Info(text, from)` | Green info log |
| `Error(text, errorType, assert)` | Red error log |
| `Warning(text)` | Warning log |
| `Assert(condition, text)` | Debug assertion |

### Stream Operators

`ImLogOut` extends `std::ostringstream` and supports `operator<<` for `ImLogColor` and `ImLogBackGroundColor`.

### Configuration

```cpp
ImLog::API::stream = &std::cout;           // default
ImLog::API::assertFunc = [](bool) { ... }; // default: assert()
```

## Build

```sh
mkdir build && cd build
cmake ..
make
```
