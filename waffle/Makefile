# $NetBSD: Makefile,v 1.1 2015/09/19 14:51:52 tnn2 Exp $

GITHUB_PROJECT=	waffle
DISTNAME=	waffle-1.5.2
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=waffle-gl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.waffle-gl.org/
COMMENT=	OpenGL runtime selection library
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	waffle.pc.in

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.if empty(BUILDLINK_LDADD.dl)
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif
.include "../../mk/bsd.pkg.mk"
