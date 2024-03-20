import os
Import("env")

# /home/patrick/Documents/PersonalProject/my_templates/platformio/.pio/build/uno/compile_commands.json
env.Execute("ln -sf $BUILD_DIR/compile_commands.json $BUILD_DIR/../../..")
