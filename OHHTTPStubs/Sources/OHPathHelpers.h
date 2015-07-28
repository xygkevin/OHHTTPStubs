/***********************************************************************************
 *
 * Copyright (c) 2012 Olivier Halligon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 ***********************************************************************************/

#import <Foundation/Foundation.h>

#ifdef NS_ASSUME_NONNULL_BEGIN
  NS_ASSUME_NONNULL_BEGIN
  #define _nullable_ __nullable
#else
  #define _nullable_
#endif


/**
 *  Useful function to build a path given a file name and a class.
 *
 *  @param fileName The name of the file to get the path to, including file extension
 *  @param inBundleForClass The class of the caller, used to determine the current bundle
 *                          in which the file is supposed to be located.
 *                          You should typically pass `self.class` (ObjC) or
 *                          `self.dynamicType` (Swift) when calling this function.
 *
 *  @return The path of the given file in the same bundle as the inBundleForClass class
 */
NSString* _nullable_ OHPathForFile(NSString* fileName, Class inBundleForClass);

/**
 *  Useful function to build a path given a file name and a bundle.
 *
 *  @param fileName The name of the file to get the path to, including file extension
 *  @param bundle The bundle in which the file is supposed to be located.
 *                This parameter can't be null.
 *
 *  @return The path of the given file in given bundle
 *
 *  @note You should avoid using `[NSBundle mainBundle]` for the `bundle` parameter,
 *        as in the context of Unit Tests, this points to the Simulator's bundle,
 *        not the bundle of the app under test. That's why `nil` is not an acceptable
 *        value (so you won't expect it to default to the `mainBundle`).
 *        You should use `[NSBundle bundleForClass:]` instead.
 */
NSString* _nullable_ OHPathForFileInBundle(NSString* fileName, NSBundle* bundle);

/**
 *  Useful function to build a path to a file in the Documents's directory in the
 *  app sandbox, used by iTunes File Sharing for example.
 *
 *  @param fileName The name of the file to get the path to, including file extension
 *
 *  @return The path of the file in the Documents directory in your App Sandbox
 */
NSString* _nullable_ OHPathForFileInDocumentsDir(NSString* fileName);



/**
 *  Useful function to build an NSBundle located in the application's resources simply from its name
 *
 *  @param bundleBasename The base name, without extension (extension is assumed to be ".bundle").
 *  @param inBundleForClass The class of the caller, used to determine the current bundle
 *                          in which the file is supposed to be located.
 *                          You should typically pass `self.class` (ObjC) or
 *                          `self.dynamicType` (Swift) when calling this function.
 *
 *  @return The NSBundle object representing the bundle with the given basename located in your application's resources.
 */
NSBundle* _nullable_ OHResourceBundle(NSString* bundleBasename, Class inBundleForClass);


#ifdef NS_ASSUME_NONNULL_END
  NS_ASSUME_NONNULL_END
#endif
