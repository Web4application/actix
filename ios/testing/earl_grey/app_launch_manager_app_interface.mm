#import "ios/testing/earl_grey/app_launch_manager_app_interface.h"

@implementation AppLaunchManagerAppInterface

+ (int)processIdentifier {
  return NSProcessInfo.processInfo.processIdentifier;
}

@
