# $NetBSD: Makefile,v 1.2 2011/05/03 23:53:48 genolopolis Exp $
#

DISTNAME=	node-v0.4.7
CATEGORIES=	wip
MASTER_SITES=	http://nodejs.org/dist/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://nodejs.org/
COMMENT=	V8 JavaScript for clients and servers
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	tools/nodejs.pc.in

DEPENDS+=               libexecinfo>=1:../../wip/libexecinfo
BUILD_DEPENDS+=         scons>=1:../../devel/scons

post-extract:
	cp -r ${WRKSRC}/deps/c-ares/openbsd-x64 ${WRKSRC}/deps/c-ares/netbsd-x64
	cp -r ${WRKSRC}/deps/c-ares/openbsd-ia32 ${WRKSRC}/deps/c-ares/netbsd-ia32

REPLACE_PYTHON+=	tools/waf-light

.include "../../lang/python26/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
