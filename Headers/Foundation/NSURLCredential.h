/* Interface for NSURLCredential for GNUstep
   Copyright (C) 2006 Software Foundation, Inc.

   Written by:  Richard Frith-Macdonald <frm@gnu.org>
   Date: 2006
   
   This file is part of the GNUstep Base Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02111 USA.
   */ 

#ifndef __NSURLCredential_h_GNUSTEP_BASE_INCLUDE
#define __NSURLCredential_h_GNUSTEP_BASE_INCLUDE

#include <Foundation/NSObject.h>

#if OS_API_VERSION(100200,GS_API_LATEST) && GS_API_VERSION(011300,GS_API_LATEST)

@class NSString;

/**
 * Controls how long a credential is retained.
 */
typedef enum {
  NSURLCredentialPersistenceNone,	/** Don't save at all */
  NSURLCredentialPersistenceForSession,	/** Save for current session */
  NSURLCredentialPersistencePermanent	/** Save forever (on disk) */
} NSURLCredentialPersistence;


/**
 * Represents a user/password credential
 */
@interface NSURLCredential : NSObject <NSCopying>
{
@private
  void *_NSURLCredentialInternal;
}

/**
 * Returns an autoreleased instance initialised using the
 * -initWithUser:password:persistence: method.
 */
+ (NSURLCredential *) credentialWithUser: (NSString *)user
  password: (NSString *)password
  persistence: (NSURLCredentialPersistence)persistence;

/**
 * Determine whether the credential has a password.
 */
- (BOOL) hasPassword;

/** <init />
 * Initialises and returns the receiver with a user name and password.<br />
 * The user identifies the credential and must be specified but the
 * password may be nil.
 */
- (id) initWithUser: (NSString *)user
	   password: (NSString *)password
	persistence: (NSURLCredentialPersistence)persistence;

/**
 * Returns the password for the receiver.<br />
 * May require prompting of the user to authorize retrieval.<br />
 * May return nil if retrieval of the password fails (eg authorization
 * failure) even if the credential actually has a password.  Call the
 * -hasPassword method to determine whether the credential has a
 * password
 */
- (NSString *) password;

/**
 * Return the presistence of this credential.
 */
- (NSURLCredentialPersistence) persistence;

/**
 * Returns the user string for the receiver
 */
- (NSString *) user;

@end

#endif
#endif