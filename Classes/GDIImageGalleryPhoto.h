//
//  GDIImageGalleryPhoto.h
//  GDIImageGallery
//
//  Created by Grant Davis on 5/20/10.
//  Copyright 2011 Grant Davis Interactive, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol GDIImageGalleryPhotoDelegate;

@interface GDIImageGalleryPhoto : NSObject {
	
	// value which determines if the photo was initialized with local file paths or network paths.
	BOOL _useNetwork;
	
	BOOL _isThumbLoading;
	BOOL _hasThumbLoaded;
	
	BOOL _isFullsizeLoading;
	BOOL _hasFullsizeLoaded;
	
	NSMutableData *_thumbData;
	NSMutableData *_fullsizeData;
	
	NSURLConnection *_thumbConnection;
	NSURLConnection *_fullsizeConnection;
	
	NSString *_thumbUrl;
	NSString *_fullsizeUrl;
	
	UIImage *_thumbnail;
	UIImage *_fullsize;
	
	NSObject <GDIImageGalleryPhotoDelegate> *__unsafe_unretained _delegate;
	
	NSUInteger tag;
}


- (id)initWithThumbnailUrl:(NSString*)thumb fullsizeUrl:(NSString*)fullsize delegate:(NSObject<GDIImageGalleryPhotoDelegate>*)delegate;
- (id)initWithThumbnailPath:(NSString*)thumb fullsizePath:(NSString*)fullsize delegate:(NSObject<GDIImageGalleryPhotoDelegate>*)delegate;

- (void)loadThumbnail;
- (void)loadFullsize;

- (void)unloadFullsize;
- (void)unloadThumbnail;

@property NSUInteger tag;

@property (readonly) BOOL isThumbLoading;
@property (readonly) BOOL hasThumbLoaded;

@property (readonly) BOOL isFullsizeLoading;
@property (readonly) BOOL hasFullsizeLoaded;

@property (nonatomic,readonly) UIImage *thumbnail;
@property (nonatomic,readonly) UIImage *fullsize;

@property (nonatomic,unsafe_unretained) NSObject<GDIImageGalleryPhotoDelegate> *delegate;

@end


@protocol GDIImageGalleryPhotoDelegate

@required
- (void)galleryPhoto:(GDIImageGalleryPhoto*)photo didLoadThumbnail:(UIImage*)image;
- (void)galleryPhoto:(GDIImageGalleryPhoto*)photo didLoadFullsize:(UIImage*)image;

@optional
- (void)galleryPhoto:(GDIImageGalleryPhoto*)photo willLoadThumbnailFromUrl:(NSString*)url;
- (void)galleryPhoto:(GDIImageGalleryPhoto*)photo willLoadFullsizeFromUrl:(NSString*)url;

- (void)galleryPhoto:(GDIImageGalleryPhoto*)photo willLoadThumbnailFromPath:(NSString*)path;
- (void)galleryPhoto:(GDIImageGalleryPhoto*)photo willLoadFullsizeFromPath:(NSString*)path;

@end
