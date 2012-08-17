
// Copyright (c) 2012 openFrameworks team
// openFrameworks is released under the MIT License. See libs/_Licence.txt

#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>
#import <QTKit/QTKit.h>
#import <OpenGL/OpenGL.h>


@interface QTKitMovieRenderer : NSObject
{
	QTMovie * _movie;
	QTVisualContextRef _visualContext;
    
	CVOpenGLTextureCacheRef _textureCache;
	CVOpenGLTextureRef _latestTextureFrame;
	CVPixelBufferRef _latestPixelFrame;
    
	NSSize movieSize;
	QTTime movieDuration;
	NSInteger frameCount;
	double frameStep;
    
	BOOL frameUpdated;
	BOOL useTexture;
	BOOL usePixels;
	BOOL allowAlpha;
	BOOL synchronousScrub;
	BOOL justSetFrame;
}

@property (nonatomic, readonly) NSSize movieSize;
@property (nonatomic, readonly) BOOL useTexture;
@property (nonatomic, readonly) BOOL usePixels;
@property (nonatomic, readwrite) BOOL allowAlpha;
@property (nonatomic, readonly) NSTimeInterval duration; //duration in seconds
@property (nonatomic, readonly) NSInteger frameCount;  //total frames
@property (nonatomic, readonly) BOOL isFinished;  //returns true if the movie is not looping and over
@property (nonatomic, readwrite) BOOL justSetFrame;
@property (nonatomic, readwrite) BOOL synchronousScrub;

@property (nonatomic, readwrite) float rate;
@property (nonatomic, readwrite) float volume;
@property (nonatomic, readwrite) CGFloat position;  //set and get frame position by percent
@property (nonatomic, readwrite) NSInteger frame;  //set and get frame position by percent
@property (nonatomic, readwrite) BOOL loops;  //set and get loopstate

@property (nonatomic, readonly) BOOL textureAllocated;
@property (nonatomic, readonly) GLuint textureID;
@property (nonatomic, readonly) GLenum textureTarget;

- (NSDictionary *)pixelBufferAttributes;

- (void)draw:(NSRect)drawRect;
- (BOOL)loadMovie:(NSString *)moviePath pathIsURL:(BOOL)isURL allowTexture:(BOOL)doUseTexture allowPixels:(BOOL)doUsePixels;
- (BOOL)update;

- (void)bindTexture;
- (void)unbindTexture;

//copies ARGB pixels to RGB or RGBA depending on allowAlpha
//outbuf must be allocated with enough space depending on movieSize
- (void)pixels:(unsigned char *)outbuf;
- (void)setBalance:(float)balance;
- (void)stepForward;
- (void)stepBackward;
- (void)gotoBeginning;

@end
