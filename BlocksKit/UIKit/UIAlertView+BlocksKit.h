//
//  UIAlertView+BlocksKit.h
//  BlocksKit
//

#import <UIKit/UIKit.h>

/** UIAlertView without delegates!

 This set of extensions and convenience classes allows
 for an instance of UIAlertView without the implementation
 of a delegate.  Any time you instantiate a UIAlertView
 using the methods here, you must add buttons using
 addButtonWithTitle:handler:otherwise nothing will happen.

 A typical invocation will go like this:
	 UIAlertView *testView = [UIAlertView alertViewWithTitle:@"Application Alert" message:@"This app will explode in 42 seconds."];
	 [testView setCancelButtonWithTitle:@"Oh No!" handler:^{ NSLog(@"Boom!"); }];
	 [testView show];

 A more traditional, and more useful, modal dialog looks like so:
	UIAlertView *testView = [UIAlertView alertViewWithTitle:@"Very important!" message:@"Do you like chocolate?"];
	[testView addButtonWithTitle:@"Yes" handler:^{ NSLog(@"Yay!"); }];
	[testView addButtonWithTitle:@"No" handler:^{ NSLog(@"We hate you."); }];
	[testView show];

 Includes code by the following:

 - [Landon Fuller](http://landonf.bikemonkey.org), "Using Blocks".
 - [Peter Steinberger](https://github.com/steipete)
 - [Zach Waldowski](https://github.com/zwaldowski)

 @warning UIAlertView is only available on a platform with UIKit.
 */
@interface UIAlertView (BlocksKit)

///-----------------------------------
/// @name Creating alert views
///-----------------------------------

/** Creates and shows a new alert view with only a title, message, and cancel button.
 
 @param title The title of the alert view.
 @param message The message content of the alert.
 @param cancelButtonTitle The title of the cancel button. If both cancelButtonTitle and otherButtonTitles are empty or nil, defaults to a 
 @param otherButtonTitles Titles of additional buttons to add to the receiver.
 @param block A block of code to be fired on the dismissal of the alert view.
 
 @return The UIAlertView.
 */
+ (UIAlertView*)bk_showAlertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles handler:(void (^)(UIAlertView *alertView, NSInteger buttonIndex))block NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** Creates and returns a new alert view with only a title and cancel button.

 @param title The title of the alert view.
 @return A newly created alert view.
 */
+ (id)bk_alertViewWithTitle:(NSString *)title NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** Creates and returns a new alert view with only a title, message, and cancel button.

 @param title The title of the alert view.
 @param message The message content of the alert.
 @return A newly created alert view.
 */
+ (id)bk_alertViewWithTitle:(NSString *)title message:(NSString *)message NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** Returns a configured alert view with only a title, message, and cancel button.
 
 @param title The title of the alert view.
 @param message The message content of the alert.
 @return An instantiated alert view.
 */
- (id)bk_initWithTitle:(NSString *)title message:(NSString *)message NS_REPLACES_RECEIVER NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

///-----------------------------------
/// @name Adding buttons
///-----------------------------------

/** Add a new button with an associated code block.
 
 @param title The text of the button.
 @param block A block of code.
 */
- (NSInteger)bk_addButtonWithTitle:(NSString *)title handler:(void (^)(void))block NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** Set the title and trigger of the cancel button.
 
 @param title The text of the button.
 @param block A block of code.
 */
- (NSInteger)bk_setCancelButtonWithTitle:(NSString *)title handler:(void (^)(void))block NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

///-----------------------------------
/// @name Altering actions
///-----------------------------------

/** Sets the block that is to be fired when a button is pressed.
 
 @param block A code block, or nil to set no response.
 @param index The index of a button already added to the action sheet.
 */
- (void)bk_setHandler:(void (^)(void))block forButtonAtIndex:(NSInteger)index NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block that is to be fired when a button is pressed.
 
 @param index The index of the button already added to the alert view.
 @return A code block, or nil if no block yet assigned.
 */
- (void (^)(void))bk_handlerForButtonAtIndex:(NSInteger)index NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block to be fired when the action sheet is dismissed with the cancel
 button.

 Contrary to setCancelButtonWithTitle:handler:, you can set this
 property multiple times but multiple cancel buttons will
 not be generated.
 */
@property (nonatomic, copy, setter = bk_setCancelBlock:) void (^bk_cancelBlock)(void) NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block to be fired before the alert view will show. */
@property (nonatomic, copy, setter = bk_setWillShowBlock:) void (^bk_willShowBlock)(UIAlertView *alertView) NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block to be fired when the alert view shows. */
@property (nonatomic, copy, setter = bk_setDidShowBlock:) void (^bk_didShowBlock)(UIAlertView *alertView) NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block to be fired before the alert view will dismiss. */
@property (nonatomic, copy, setter = bk_setWillDismissBlock:) void (^bk_willDismissBlock)(UIAlertView *alertView, NSInteger buttonIndex) NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block to be fired after the alert view dismisses. */
@property (nonatomic, copy, setter = bk_setDidDismissBlock:) void (^bk_didDismissBlock)(UIAlertView *alertView, NSInteger buttonIndex) NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

/** The block to be fired to determine whether the first non-cancel should be enabled */
@property (nonatomic, copy, setter = bk_SetShouldEnableFirstOtherButtonBlock:) BOOL (^bk_shouldEnableFirstOtherButtonBlock)(UIAlertView *alertView) NS_AVAILABLE_IOS(5_0) NS_EXTENSION_UNAVAILABLE_IOS("Not available in app extensions.");

@end
