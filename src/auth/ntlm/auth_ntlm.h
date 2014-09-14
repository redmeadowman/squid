/*
 * Copyright (C) 1996-2014 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

#ifndef __AUTH_NTLM_H__
#define __AUTH_NTLM_H__

#include "auth/Config.h"
#include "auth/Gadgets.h"
#include "auth/UserRequest.h"
#include "helper.h"

#define DefaultAuthenticateChildrenMax  32	/* 32 processes */

class HttpRequest;
class StoreEntry;

namespace Auth
{
namespace Ntlm
{

/** NTLM Authentication configuration data */
class Config : public Auth::Config
{
public:
    Config();
    virtual bool active() const;
    virtual bool configured() const;
    virtual Auth::UserRequest::Pointer decode(char const *proxy_auth, const char *requestRealm);
    virtual void done();
    virtual void rotateHelpers();
    virtual bool dump(StoreEntry *, const char *, Auth::Config *) const;
    virtual void fixHeader(Auth::UserRequest::Pointer, HttpReply *, http_hdr_type, HttpRequest *);
    virtual void init(Auth::Config *);
    virtual void parse(Auth::Config *, int, char *);
    virtual void registerWithCacheManager(void);
    virtual const char * type() const;

public:
    int keep_alive;
};

} // namespace Ntlm
} // namespace Auth

extern statefulhelper *ntlmauthenticators;

#endif
