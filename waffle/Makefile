# $NetBSD: Makefile,v 1.1 2015/09/19 14:51:52 tnn2 Exp $

GITHUB_PROJECT=	waffle
DISTNAME=	waffle-v1.7.0
PKGNAME=	${DISTNAME:C/waffle-v/waffle-/}
CATEGORIES=	graphics x11
MASTER_SITES=	https://gitlab.freedesktop.org/mesa/waffle/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/mesa/waffle/
COMMENT=	OpenGL runtime selection library
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	waffle.pc.in

.include "../../devel/cmake/build.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.if empty(BUILDLINK_LDADD.dl)
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif
.include "../../mk/bsd.pkg.mk"
