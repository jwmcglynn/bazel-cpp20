# bazel-cpp20: Template for bazel with C++20

This template sets up a coding environment for C++20 with VSCode, GitHub, and Clang.

## Requirements

* Bazel

### Install Bazel

The recommended way to use Bazel is to install **Bazelisk**, which will automatically download Bazel as required. To install:

1. Navigate to the Bazelisk releases page: https://github.com/bazelbuild/bazelisk/releases
2. Download the latest release, and install it as `~/bin/bazel`
3. `chmod +x ~/bin/bazel`
4. Update your `~/.bashrc` (or equivalent) to add this directory to your path:
    ```
    export PATH=$PATH:$HOME/bin
    ```

## macOS: Install XCode

On Linux, this workspace is configured to automatically download Clang and configure it as a toolchain, but that mode does not support Apple Silicon yet.  So to enable building for macOS, the system toolchain is used instead.

Note that on macOS fuzzing builds are not yet supported.

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

## Devcontainer

To use the devcontainer, install the VSCode [Remote - Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension.

### Command History Syncing

Command history syncing hooks, based on the [Advanced Containers: Persist bash history](https://code.visualstudio.com/remote/advancedcontainers/persist-bash-history) docs, are included.  Final registration is required to enable them, so it is recommended to use Dotfiles and add the following registration:

#### Zsh Registration
```
# See https://code.visualstudio.com/remote/advancedcontainers/persist-bash-history
if [ -d /commandhistory ]; then
  touch /commandhistory/.zsh_history
  export HISTFILE="/commandhistory/.zsh_history"
else
  echo "Warning: Could not enable history sharing, there is no /commandhistory directory."
fi
```

#### Bash Registration
```
# See https://code.visualstudio.com/remote/advancedcontainers/persist-bash-history
if [ -d /commandhistory ]; then
  touch /commandhistory/.bash_history
  export PROMPT_COMMAND='history -a'
  export HISTFILE="/commandhistory/.bash_history"
else
  echo "Warning: Could not enable history sharing, there is no /commandhistory directory."
fi
```
