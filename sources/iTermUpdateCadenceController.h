//
//  iTermUpdateCadenceController.h
//  iTerm2
//
//  Created by George Nachman on 8/1/17.
//
//

#import <Cocoa/Cocoa.h>

@class iTermHistogram;
@class iTermThroughputEstimator;
@class iTermUpdateCadenceController;

typedef struct {
    BOOL active;
    BOOL idle;
    BOOL visible;
    BOOL useAdaptiveFrameRate;
    NSInteger adaptiveFrameRateThroughputThreshold;
    double slowFrameRate;
    BOOL liveResizing;
    BOOL proMotion;
    NSInteger estimatedThroughput;
} iTermUpdateCadenceState;

@protocol iTermUpdateCadenceControllerDelegate<NSObject>

// Time to update the display.
- (void)updateCadenceControllerUpdateDisplay:(iTermUpdateCadenceController *)controller;

// Returns the current state of the delegate.
- (iTermUpdateCadenceState)updateCadenceControllerState;

- (void)cadenceControllerActiveStateDidChange:(BOOL)active;

- (BOOL)updateCadenceControllerWindowHasSheet;

@end

@interface iTermUpdateCadenceController : NSObject

@property (nonatomic, readonly) BOOL updateTimerIsValid;
@property (nonatomic, weak) id<iTermUpdateCadenceControllerDelegate> delegate;
@property (nonatomic, readonly) iTermHistogram *histogram;
@property (nonatomic, readonly) BOOL isActive;

- (instancetype)init;

- (void)changeCadenceIfNeeded;

- (void)willStartLiveResize;
- (void)liveResizeDidEnd;
- (void)didHandleInputWithThroughput:(NSInteger)throughput;
- (void)didHandleKeystroke;

@end
