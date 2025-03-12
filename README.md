# cpp-skeleton
The initial purpose of this project was to produce working example of building a cpp application with logging (l0g4cplus).

The future vision is to serve as a skeleton for cpp application with configurable modules.

The modules could be something like:
</br>
SKELETON_USE_LOG4CPLUS
</br>
SKELETON_USE_SOMEMODULE

## Build instructions
You can build any tool supporting digesting the `CMakeLists.txt` including vscode or vstudio but the workflow and configuration is tool specific.

The following is the instructions on how to build using docker and ubuntu.
The ubuntu example is based on the docker build and is basically just overview of it.

## Preparations
This guideline was written on Windows 10.

### Required build tools
Docker installed.
[docker-windows](https://docs.docker.com/desktop/setup/install/windows-install/)
Git installed
[git-windows](https://git-scm.com/downloads/win)
#### Docker build and run example:
```shell
git clone https://github.com/head5man/cpp-skeleton.git
cd cpp-skeleton
# Build the image defined in ./Dockerfile
docker build -t build_image_name .
# Run container with interactive terminal
docker run -it --name=build_container_name build_image_name /bin/bash
# To run test executable
build_container_name:/usr/src/app/build# ./tests/skeleton-test
# To run application example
build_container_name:/usr/src/app/build# cd example && ./skeleton-example
# Exit and delete container and image
build_container_name:/usr/src/app/build# exit
docker rm build_container_name
docker rmi build_image_name
```

#### Ubuntu 22.04 build and run example
```bash
apt-get update 
apt-get install build-essential -y
apt-get install cmake -y
apt-get install git -y

# Clone repository to home and build
cd ~
git clone https://github.com/head5man/cpp-skeleton.git
cmake -S cpp-skeleton -B cpp-skelton/build
cmake --build cpp-skeleton/build

# To run test executable
cpp-skeleton/build/tests/skeleton-test

# To run application example
cd cpp-skeleton/build/example && ./skeleton-example
```
