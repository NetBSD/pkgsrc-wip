# $NetBSD: Makefile,v 1.2 2013/08/12 01:26:33 othyro Exp $

DISTNAME=	SDL2_ttf-2.0.12
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/tmp/SDL_ttf/release/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/tmp/SDL_ttf/
COMMENT=	Sample library allowing for using TrueType fonts in SDL applications
LICENSE=	zlib

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	SDL2_ttf.pc.in

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
