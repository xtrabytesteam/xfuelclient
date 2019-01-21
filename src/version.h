// Copyright (c) 2012 The Bitcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef XFUEL_VERSION_H
#define XFUEL_VERSION_H

#include "clientversion.h"
#include <string>

//
// client versioning
//

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

//
// network protocol versioning
//

static const int PROTOCOL_VERSION_SHORT = 1;

static const int PROTOCOL_VERSION = 10001;

// intial proto version, to be increased after version/verack negotiation
static const int INIT_PROTO_VERSION = 1;

// disconnect from peers older than this proto version
static const int MIN_PEER_PROTO_VERSION = 10001;


#endif
