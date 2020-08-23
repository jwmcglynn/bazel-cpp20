ARG VARIANT=focal
FROM mcr.microsoft.com/vscode/devcontainers/base:${VARIANT}

#
# Install base dependencies
#
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        software-properties-common

#
# Install LLVM
#
RUN mkdir -p /tmp/llvm \
    && cd /tmp/llvm \
    && wget https://apt.llvm.org/llvm.sh \
    && chmod +x ./llvm.sh \
    && ./llvm.sh 10 \
    && rm -rf /tmp/llvm

# Install libc++
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        libc++-10-dev libc++abi-10-dev

# Update path so this clang is first.
ENV PATH=/usr/lib/llvm-10/bin:${PATH}

#
# Install bazelisk
#
RUN mkdir -p /tmp/bazelisk \
    && cd /tmp/bazelisk \
    && wget https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 \
    && mv bazelisk-linux-amd64 /usr/local/bin/bazel \
    && chmod +x /usr/local/bin/bazel \
    && rm -rf /tmp/bazelisk
