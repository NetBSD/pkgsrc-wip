# $NetBSD: Makefile,v 1.1.1.1 2009/10/06 01:17:03 mbowie Exp $
#

DISTNAME=       libmemcached-0.33
CATEGORIES=     devel
MASTER_SITES=   http://download.tangent.org/

MAINTAINER=     mbowie@buzmo.com
HOMEPAGE=       http://tangent.org/552/libmemcached.html
COMMENT=        C and C++ client library to the memcached server
LICENSE=        original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	support/libmemcached.pc.in

.include "../../mk/bsd.pkg.mk"
