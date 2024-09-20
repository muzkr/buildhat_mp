

# RPI Build HAT


This board definition is for the RaspberryPi Build HAT.


## Hardware Configuration

See [doc/bh_hw.md](./doc/bh_hw.md).

## MicroPython Features



## Build

First of all, we need to get the micropython source code, and do some initial work.

```sh
git clone https://github.com/micropython/micropython.git --branch master
cd micropython
make -C mpy-cross
cd ports/rp2
make BOARD=RPI_PICO submodules
```

To perform cmake configuration, in the `ports/rp2` directory execute

```sh
cmake -G"Unix Makefiles" -DCMAKE_VERBOSE_MAKEFILE:BOOL=TRUE \
-DMICROPY_BOARD:STRING=RPI_BUILD_HAT \
-DMICROPY_BOARD_DIR:STRING=<loc>/buildhat_mp/port/RPI_BUILD_HAT \
-B build-RPI_BUILD_HAT
```

, where `<loc>` is the path to the `buildhat_mp` repository. Note that `buildhat_mp`
(the board port) is **out of** the micropython source tree.

We can now actually build the port.

```sh
make -C build-RPI_BUILD_HAT
```

If everything went well, the newly generated firmware binaries (`firmware.elf`/`.uf2`) 
can be found in the `build-RPI_BUILD_HAT` dir.


## Install


### Install with OpenOCD

Connect SWD pins (consult [doc/bh_hw.md](./doc/bh_hw.md#swd) to locate them) to the debugger adapter and run OpenOCD:

```sh
openocd ... -f target/rp2040.cfg -c "program firmware.elf verify reset exit"
```

This will override/replace the official Build HAT bootloader. The [Hachi](https://github.com/muzkr/hachi) bootloader provides instructions of recovery. 


### Install with Hachi Bootloader 

Please ref to [Hachi](https://github.com/muzkr/hachi) for details.

