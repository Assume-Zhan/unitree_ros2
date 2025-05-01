FROM osrf/ros:foxy-desktop

LABEL org.opencontainers.image.authors="assume0701@gmail.com"

ARG USERNAME=user

#############################################
# --- Basic setup ---
RUN apt-get update && \
    apt-get install -y \
                sudo \
                vim \
                curl \
                tree \
                tmux && \
                rm -rf /var/lib/apt/lists/*

# add user with default bash
RUN adduser --disabled-password --gecos '' --shell /bin/bash ${USERNAME} && \
    adduser ${USERNAME} sudo && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

COPY .bashrc /home/$USERNAME/.bashrc

# Login with user
USER ${USERNAME}

CMD ["bash"]