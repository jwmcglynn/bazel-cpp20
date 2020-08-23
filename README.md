# bazel-cpp20: Template for bazel with C++20

This template sets up a coding environment for C++20 with VSCode, GitHub, and Clang.

## Requirements

* Bazel
* Clang-10

### Install Bazel

The recommended way to use Bazel is to install **Bazelisk**, which will automatically download Bazel as required. To install:

1. Navigate to the Bazelisk releases page: https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
2. Download the latest releases, and install it as `~/bin/bazel`
3. `chmod +x ~/bin/bazel`
4. Update your `~/.bashrc` (or equivalent) to add this directory to your path:
    ```
    export PATH=$PATH:$HOME/bin
    ```

### Installing Clang-10

To install Clang-10, follow the instructions to install it on the main LLVM site. For Ubuntu 18.04, the instructions are at https://apt.llvm.org/

```
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 10
```

You'll also need to manually install `libc++-10`, which should now work with apt after running `llvm.sh`:

```
sudo apt-get install libc++-10-dev libc++abi-10-dev
```

Then update your path so that clang-10 is at the start, again in `~/.bashrc` or equivalent:

```
export PATH=/usr/lib/llvm-10/bin:$PATH
```

Verify this works with

```
clang -v
```

## That's it!

Verify that you can build with

```
bazel build //...
```

All other dependencies will be downloaded on-demand.

## Running Tests

This repository is set up with gtest and a simple `cc_fuzzer` wrapper. To run tests:

```
bazel test //...
```

To run the fuzzer:

```
bazel build --config=asan-fuzzer //sample:sample_fuzzer
bazel-bin/sample/sample_fuzzer
```
