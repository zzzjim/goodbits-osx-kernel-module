# BUILDING AN APPLE OSX KERNEL MODULE WITH CMAKE – C/C++

Code to accompany article: http://www.goodbits.ca/index.php/2017/09/25/building-an-apple-osx-kernel-module-with-cmake-cc/

A basic OSX kernel module that is built with CMake.

Depenencies: CMake, Xcode SDK

# Build Instructions:

```
git clone https://github.com/zzzjim/goodbits-osx-kernel-module

cd goodbits-osx-kernel-module
mkdir build
cd build
cmake ../
make
sudo chown -R root:wheel example.kext/
sudo kextload example.kext/
sudo kextunload example.kext/

sudo dmesg
```


# Output
loaded example

example unloading.

# Notes
If system integrity protection is enabled and code signing is not enabled the module it will not load.



