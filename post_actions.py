import os
import shutil

Import("env")


def post_copy(target, source, env):
    src = os.path.join(os.getcwd(), str(target[0]))
    dest = os.path.join(os.getcwd(), "build/firmware.hex")
    if not os.path.exists(os.path.dirname(dest)):
        os.makedirs(os.path.dirname(dest))

    shutil.copy(src, dest)
    print("Copied", src, "to", dest)


env.AddPostAction("$BUILD_DIR/firmware.hex", post_copy)
