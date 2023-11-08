//
// UIScrollView+SVInfiniteScrolling.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>

@class SVInfiniteScrollingView;

typedef NS_ENUM(NSUInteger, SVInfiniteScrollingPosition){
    SVInfiniteScrollingPositionTop,
    SVInfiniteScrollingPositionBottom
};

@interface UIScrollView (SVInfiniteScrolling)

- (void)addInfiniteScrolling:(void (^)(void))actionHandler;
- (void)addInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler forPosition:(SVInfiniteScrollingPosition)position;
- (void)triggerInfiniteScrollingForPosition:(SVInfiniteScrollingPosition)position;

- (SVInfiniteScrollingView *)infiniteScrollingViewForPosition:(SVInfiniteScrollingPosition)position;
- (BOOL)showsInfiniteScrollingForPosition:(SVInfiniteScrollingPosition)position;
- (void)setShowsInfiniteScrolling:(BOOL)visible forPosition:(SVInfiniteScrollingPosition)position;

// Fast accessor for bottom InfiniteScrollingView

@property (nonatomic, strong, readonly) SVInfiniteScrollingView *infiniteScrollingView;

@end

typedef NS_ENUM(NSUInteger, SVInfiniteScrollingState){
    SVInfiniteScrollingStateStopped = 0,
    SVInfiniteScrollingStateTriggered,
    SVInfiniteScrollingStateLoading,
    SVInfiniteScrollingStateAll = 10
};

@interface SVInfiniteScrollingView : UIView

@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, readonly) SVInfiniteScrollingState state;
@property (nonatomic, readonly) SVInfiniteScrollingPosition position;
@property (nonatomic, readwrite) BOOL enabled;
@property (nonatomic, readwrite) BOOL stopsWithoutAnimation;

- (void)setCustomView:(UIView *)view forState:(SVInfiniteScrollingState)state;

- (void)startAnimating;
- (void)stopAnimating;

@end
