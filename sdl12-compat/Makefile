# $NetBSD: Makefile,v 1.6 2023/05/06 19:09:11 ryoon Exp $

DISTNAME=	sdl12-compat-1.2.68
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/libsdl-org/sdl12-compat
COMMENT=	SDL-1.2 compatibility layer that uses SDL 2.0 behind the scenes
LICENSE=	zlib

CONFLICTS+=	SDL-[0-9]*

PKGCONFIG_OVERRIDE+=	sdl12_compat.pc.in

BUILDLINK_DEPMETHOD.SDL2=	build
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
