# Building the firmware

```shell
./util/docker_build.sh splitkb/aurora/lily58:kenranunderscore
```

# Flashing

- Press the reset button on the PCB
- Mount the device somewhere, like `sudo mount /dev/sdc1 /media/usb`
- `cp my_firmware.uf2 /media/usb`
- Done
