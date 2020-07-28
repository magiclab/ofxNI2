# Setup

## OSX


Add to Run Script

	cp -R ../../../addons/ofxNI2/libs/OpenNI2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
	cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";

Uncomment

    //#define HAVE_NITE2

in `ofxNI2.h` to use NiTE2.

### Drivers
To switch to new OpenNI device drivers:

* copy your drivers to `ofxNI2/libs/OpenNI2/lib/[your_platform]/Drivers`
* relink the libraries that need relinking.

See the Run Script of the example.

## Visual Studio

The project includes 64bit Windows libraries for OpenNI2 and NiTE2.
After adding the addon to a project in the usual way:
- copy the content of *toVSProjectFolder* into the project folder (same level as .sln file)
- run the *copyLibs.cmd* script you just copied
- drag NiTE2.lib and OpenNI2.lib into the Solution Explorer

To use Microsoft Kinect through OpenNI2, install Microsoft SDK 1.x as well.

