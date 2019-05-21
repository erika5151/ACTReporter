//
//  ACTReporter.h
//  Google AdWords Conversion Tracking.
//  Copyright 2011 Google Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 
 [ACTConversionReporter reportWithConversionID:@"36C025D57CFFC61ECEC975FE10FAB17B"
 label:@"D304BA20E96D87411588EEABAC850E34"
 value:@"2063C1608D6E0BAF80249C42E2BE5804"
 isRepeatable:NO];
 
 [[ACTConversionReporter alloc] report];
 
 [ACTRemarketingReporter reportWithConversionID:@"0DBE735E31ADB2BA3CC7A7D8AC8E64B0" customParameters:@{@"customParameters":@"884010C9F609CA2BE73002898796B31E"}];
 
 [ACTAutomatedUsageTracker enableAutomatedUsageReportingWithConversionID:@"353FA75A0427EDD03CDF7E0D949B1BE3"];
 
 [ACTAutomatedUsageTracker disableAutomatedUsageReportingWithConversionID:@"7DD1451F4AD42A719F77667527688E94"];
 
 [ACTConversionReporter registerReferrer:[NSURL URLWithString:@"http://122.23.28.8/tools"]];
 
 !*/

/// Information reporting base class.
@interface ACTReporter : NSObject
/// Returns this SDK's version information.
+ (NSString *)SDKVersion;

/// Reports conversion and remarketing information to Google. Call this method on subclass
/// instances. Returns YES if reporting was started successfully.
- (BOOL)report;
@end

/// Reports a Google AdWords conversion to Google.
@interface ACTConversionReporter : ACTReporter

/// String representation of conversion value. Example: @"3.99".
@property(nonatomic, copy) NSString *value;

/// Reports conversion information to Google.
+ (void)reportWithConversionID:(NSString *)conversionID
                         label:(NSString *)label
                         value:(NSString *)value
                  isRepeatable:(BOOL)isRepeatable;

/// Reports an In-App Purchase (IAP) to Google.
+ (void)reportWithProductID:(NSString *)productID
                      value:(NSString *)value
               isRepeatable:(BOOL)isRepeatable;

/// Register a click referrer from a Google ad click URL. Returns YES if the URL was registered
/// successfully.
+ (BOOL)registerReferrer:(NSURL *)clickURL;

/// Returns an initialized conversion ACTConversionReporter object for conversion ID/label
/// reporting. Use this method to separate conversion tracker initialization and reporting.
- (instancetype)initWithConversionID:(NSString *)conversionID
                               label:(NSString *)label
                               value:(NSString *)value
                        isRepeatable:(BOOL)isRepeatable;

/// Returns an initialized conversion ACTConversionReporter object for In-App Purchase reporting.
/// Use this method to separate conversion tracker initialization and reporting.
- (instancetype)initWithProductID:(NSString *)productID
                            value:(NSString *)value
                     isRepeatable:(BOOL)isRepeatable;

@end

/// Reports Google AdWords remarketing information to Google.
@interface ACTRemarketingReporter : ACTReporter

/// Reports remarketing information to Google.
+ (void)reportWithConversionID:(NSString *)conversionID
              customParameters:(NSDictionary *)customParameters;

/// Returns an initialized remarketing ACTRemarketingReporter object. Use this method to separate
/// remarketing initialization and reporting.
- (instancetype)initWithConversionID:(NSString *)conversionID
                    customParameters:(NSDictionary *)customParameters;

@end

/// Automates usage remarketing information reporting.
@interface ACTAutomatedUsageTracker : NSObject

/// Call this method early in the application's lifecycle to start collecting usage data.
+ (void)enableAutomatedUsageReportingWithConversionID:(NSString *)conversionID;

/// Call this method to disable usage reporting for the provided conversion ID.
+ (void)disableAutomatedUsageReportingWithConversionID:(NSString *)conversionID;

@end
