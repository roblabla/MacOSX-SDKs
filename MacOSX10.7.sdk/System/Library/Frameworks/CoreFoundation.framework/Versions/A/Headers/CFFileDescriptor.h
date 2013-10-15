/*	CFFileDescriptor.h
	Copyright (c) 2006-2011, Apple Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFFILEDESCRIPTOR__)
#define __COREFOUNDATION_CFFILEDESCRIPTOR__ 1

#include <CoreFoundation/CFRunLoop.h>


CF_EXTERN_C_BEGIN

typedef int CFFileDescriptorNativeDescriptor;

typedef struct __CFFileDescriptor * CFFileDescriptorRef;

/* Callback Reason Types */
enum {
    kCFFileDescriptorReadCallBack = 1UL << 0,
    kCFFileDescriptorWriteCallBack = 1UL << 1
};

typedef void (*CFFileDescriptorCallBack)(CFFileDescriptorRef f, CFOptionFlags callBackTypes, void *info);

typedef struct {
    CFIndex	version;
    void *	info;
    void *	(*retain)(void *info);
    void	(*release)(void *info);
    CFStringRef	(*copyDescription)(void *info);
} CFFileDescriptorContext;

CF_EXPORT CFTypeID	CFFileDescriptorGetTypeID(void) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT CFFileDescriptorRef	CFFileDescriptorCreate(CFAllocatorRef allocator, CFFileDescriptorNativeDescriptor fd, Boolean closeOnInvalidate, CFFileDescriptorCallBack callout, const CFFileDescriptorContext *context) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT CFFileDescriptorNativeDescriptor	CFFileDescriptorGetNativeDescriptor(CFFileDescriptorRef f) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT void	 CFFileDescriptorGetContext(CFFileDescriptorRef f, CFFileDescriptorContext *context) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT void	 CFFileDescriptorEnableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes) CF_AVAILABLE(10_5, 2_0);
CF_EXPORT void	 CFFileDescriptorDisableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT void	 CFFileDescriptorInvalidate(CFFileDescriptorRef f) CF_AVAILABLE(10_5, 2_0);
CF_EXPORT Boolean	CFFileDescriptorIsValid(CFFileDescriptorRef f) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT CFRunLoopSourceRef	CFFileDescriptorCreateRunLoopSource(CFAllocatorRef allocator, CFFileDescriptorRef f, CFIndex order) CF_AVAILABLE(10_5, 2_0);


CF_EXTERN_C_END


#endif /* ! __COREFOUNDATION_CFFILEDESCRIPTOR__ */

