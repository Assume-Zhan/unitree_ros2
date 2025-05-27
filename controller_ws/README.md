# Wrapped Unitree ROS2

## Install with docker

- Run the docker container

    ```bash
    cd docker/
    docker compose up -d --build
    ```

- Install by the script
    
    ```bash
    # In the container
    cd ~/workspace
    ./scripts/install.sh
    ```

## Run the converter node

- Run the converter node

    ```bash
    # In the container
    source ~/.bashrc
    ros2 launch go2_controller run.launch.py
    ```

---

## Issues

In the CyCloneDDS setting, the priority should larger than the network interface `lo`, you could use the following to checkout whether the priority is correct set.

```xml
<CycloneDDS>
    <Domain>
        <General>
            <Interfaces>
                <NetworkInterface name="enp4s0" priority="3" multicast="default" />
            </Interfaces>
        </General>

        <Tracing>
            <Verbosity>finest</Verbosity>
        </Tracing>
    </Domain>
</CycloneDDS>
```