#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface KPKit : NSObject

// Credits
// http://matt.coneybeare.me/my-favorite-macros-for-objective-c-development-in-xcode/
// https://github.com/mureev/ObjCMacros/blob/master/ObjCMacros/ObjCMacros.h
// http://lists.apple.com/archives/xcode-users/2005/Dec/msg00707.html
// https://github.com/openframeworks/openFrameworks/tree/master/libs/openFrameworks/math
// http://nshipster.com/__attribute__/

// Macros
#define KP_IS_IPHONE ([[[UIDevice currentDevice] model] isEqualToString:@"iPhone"] || [[[UIDevice currentDevice] model] isEqualToString:@"iPhone Simulator"])
#define KP_IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])
#define KP_IS_IPAD ([[[UIDevice currentDevice] model] isEqualToString:@"iPad"] || [[[UIDevice currentDevice] model] isEqualToString:@"iPad Simulator"])
#define KP_IS_IPHONE_UI ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPhone)
#define KP_IS_IPAD_UI ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
#define KP_IS_WIDESCREEN (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)568) < DBL_EPSILON)
#define KP_IS_RETINA ([[UIScreen mainScreen] respondsToSelector:@selector(scale)] && [[UIScreen mainScreen] scale] >= 2)
#define KP_IS_MULTITASKING                                                                                                                                     \
  ([[UIDevice currentDevice] respondsToSelector:@selector(isMultitaskingSupported)] && [[UIDevice currentDevice] isMultitaskingSupported])
#define KP_COLOR_RGBA(r, g, b, a) [UIColor colorWithRed:r / 255.0f green:g / 255.0f blue:b / 255.0f alpha:a]
#define KP_COLOR_RGB(r, g, b) LP_RGBA(r, g, b, 1.0f)
#define KP_COLOR_HEX(hex)                                                                                                                                      \
  [UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16)) / 255.0 green:((float)((hex & 0xFF00) >> 8)) / 255.0 blue:((float)(hex & 0xFF)) / 255.0 alpha:1.0]
#define KP_LOG_FUNCTION NSLog((@"%s (%s:%d)"), __PRETTY_FUNCTION__, ((strrchr(__FILE__, '/') ?: __FILE__ - 1) + 1), __LINE__);

// Random (TODO convert to overloadable functions)
+ (NSInteger)randomInt:(NSInteger)value;
+ (CGFloat)randomBetweenA:(CGFloat)a andB:(CGFloat)b;
+ (NSInteger)randomIntBetweenA:(NSInteger)a andB:(NSInteger)b;

// Color (TODO convert to overloadable functions)
+ (UIColor *)randomColor;
+ (UIColor *)colorWithAlpha:(UIColor *)color alpha:(CGFloat)alpha;
+ (UIColor *)randomColorWithAlpha:(CGFloat)alphaValue;
+ (UIColor *)randomBrightnessOfColor:(UIColor *)color;
+ (UIColor *)color:(UIColor *)color withBrightness:(CGFloat)value;

// File System
+ (NSURL *)documentDirectory;
+ (NSURL *)tempDirectory;
+ (NSURL *)cacheDirectory;
+ (void)clearTempDirectory;
+ (void)clearCacheDirectory;

// Text
+ (void)drawText:(NSAttributedString *)text onPath:(UIBezierPath *)path;
+ (void)drawText:(NSAttributedString *)text onPath:(UIBezierPath *)path inContext:(CGContextRef)context;
+ (void)drawText:(NSAttributedString *)text onPath:(UIBezierPath *)path inContext:(CGContextRef)context withAlignment:(NSTextAlignment)alignment;
+ (void)drawText:(NSAttributedString *)text
               onPath:(UIBezierPath *)path
            inContext:(CGContextRef)context
        withAlignment:(NSTextAlignment)alignment
    clockwiseBaseline:(BOOL)clockwiseBaseline;

// Foundation type helpers

CGFloat KPMagnitudeOfVector(CGVector vector);
BOOL KPVectorEqualToVector(CGVector vectorA, CGVector vectorB);

CGFloat KPAngleBetweenCGPoint(CGPoint startPoint, CGPoint endPoint);
CGFloat KPDistanceBetweenCGPoint(CGPoint startPoint, CGPoint endPoint);
CGPoint KPLinearInterpolateBetweenCGPoint(CGPoint startPoint, CGPoint endPoint, CGFloat amount);
CGPoint KPPolarToCartesian(CGFloat theta, CGFloat radius);

// Arrays
+ (id)randomObjectIn:(NSArray *)array;
+ (NSNumber *)meanOf:(NSArray *)array;
+ (NSNumber *)standardDeviationOf:(NSArray *)array;

// Images
+ (UIImage *)imageFromColor:(UIColor *)color;

// Views
+ (UIView *)firstSuperviewOfView:(UIView *)view thatIsKindOfClass:(__unsafe_unretained Class)someClass;



@end