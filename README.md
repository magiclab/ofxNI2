Setup
========

OSX
--------
Add dylib libraries for OpenNI2, NiTE2 and any exotic driver you might be using to Linking->Other Linker Flags.

In Run Script:

	############################
	# NiTE2
	############################
	# copy NiTE library and files into the bundle
	cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
	############################
	# OpenNI2
	############################
	# Copy OpenNI library into the bundle
	cp -R ../../../addons/ofxNI2/libs/OpenNI2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
	# If you use OpenNI 2.2.0.3 from Structure, you need to change its path (use otool -L, if in doubt)
	install_name_tool -change libOpenNI2.dylib @executable_path/libOpenNI2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";

If you're using exotic drivers, you might also have to relink them. I.e. this is the setup for libroyale based drivers:

	############################
	# Drivers
	############################
	# By default all drivers in lib/osx/OpenNI2/Drivers will be copied into the bundle; if you want less, jut edit the previous passage

	#if you're planning to load libroyale drivers, prepare to relink a bunch of stuff
	install_name_tool -change @rpath/libspectre3.dylib @executable_path/OpenNI2/Drivers/libspectre3.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";
	install_name_tool -change @rpath/libuvc.dylib @executable_path/OpenNI2/Drivers/libuvc.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";
	install_name_tool -change @rpath/libroyale.3.12.0.dylib @executable_path/OpenNI2/Drivers/libroyale.3.12.0.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";
	install_name_tool -change @rpath/libroyaleONI2.0.dylib @executable_path/OpenNI2/Drivers/libroyaleONI2.0.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";
	install_name_tool -change libOpenNI2.dylib @executable_path/libOpenNI2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/OpenNI2/Drivers/libroyaleONI2.0.dylib";

Uncomment

    //#define HAVE_NITE2

in `ofxNI2.h` to use NiTE2.

Visual Studio
--------

The project includes 64bit Windows libraries for OpenNI2 and NiTE2.
After adding the addon to a project in the usual way:
- copy the content of *toVSProjectFolder/winXX* (where XX is your architecture) into the project folder (same level as .sln file)
- run the *copyLibs.cmd* script you just copied
- drag NiTE2.lib and OpenNI2.lib into the Solution Explorer

To use Microsoft Kinect through OpenNI2, install Microsoft SDK 1.x as well.

PMD drivers are included, but they only support 32bit and do not work with NiTE.
