#import <XCTest/XCTest.h>
//
// Import the application specific header files
#import "CalcViewController.h"
#import "CalcAppDelegate.h"
 
@interface CalcTests : XCTestCase {
// add instance variables to the CalcTests class
@private
    NSApplication       *app;
    CalcAppDelegate     *appDelegate;
    CalcViewController  *calcViewController;
    NSView              *calcView;
}
@end

- (void) testAddition
{
   // obtain the app variables for test access
   app                  = [NSApplication sharedApplication];
   calcViewController   = (CalcViewController*)[[NSApplication sharedApplication] delegate];
   calcView             = calcViewController.view;
 
   // perform two addition tests
   [calcViewController press:[calcView viewWithTag: 6]];  // 6
   [calcViewController press:[calcView viewWithTag:13]];  // +
   [calcViewController press:[calcView viewWithTag: 2]];  // 2
   [calcViewController press:[calcView viewWithTag:12]];  // =
    XCTAssertEqualObjects([calcViewController.displayField stringValue], @"8", @"Part 1 failed.");
 
   [calcViewController press:[calcView viewWithTag:13]];  // +
   [calcViewController press:[calcView viewWithTag: 2]];  // 2
   [calcViewController press:[calcView viewWithTag:12]];  // =
    XCTAssertEqualObjects([calcViewController.displayField stringValue], @"10", @"Part 2 failed.");
}

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
 
   // obtain the app variables for test access
   app                  = [NSApplication sharedApplication];
   calcViewController   = (CalcViewController*)[[NSApplication sharedApplication] delegate];
   calcView             = calcViewController.view;
}
