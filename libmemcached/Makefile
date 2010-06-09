# $NetBSD: Makefile,v 1.4 2010/06/09 11:27:44 fhajny Exp $
#

DISTNAME=	libmemcached-0.33
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	mbowie@buzmo.com
HOMEPAGE=	http://tangent.org/552/libmemcached.html
COMMENT=	C and C++ client library to the memcached server
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	support/libmemcached.pc.in

.include "../../mk/bsd.prefs.mk"
.include "options.mk"
.include "../../mk/compiler.mk"

# GCC 3.4.3 on Solaris doesn't support no-attributes with CXX
.if ${OPSYS} == SunOS && !empty(CC_VERSION:Mgcc-3*)
SUBST_CLASSES+=		gcc
SUBST_STAGE.gcc=	post-configure
SUBST_MESSAGE.gcc=	Removing -Wno-attributes for CXX on Solaris/GCC 3.x
SUBST_FILES.gcc=	tests/Makefile
SUBST_SED.gcc=		-e '/AM_CXXFLAGS/s/ -Wno-attributes//'
.endif

.if !empty(ABI) && ${ABI} != 64
CONFIGURE_ARGS+=	--disable-64bit
.endif

.include "../../mk/bsd.pkg.mk"
