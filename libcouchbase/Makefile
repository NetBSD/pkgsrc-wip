# $NetBSD: Makefile,v 1.4 2014/07/30 13:58:57 fhajny Exp $

DISTNAME=	libcouchbase-2.5.6
CATEGORIES=	devel
MASTER_SITES=	http://packages.couchbase.com/clients/c/

MAINTAINER=	trond.norbye@gmail.com
HOMEPAGE=	http://www.couchbase.com/develop/c/next
COMMENT=	C/C++ client library to access a Couchbase server
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

# Prevents CouchbaseMock.jar fetching at build time
CMAKE_ARGS+=		-DLCB_NO_MOCK=ON

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
