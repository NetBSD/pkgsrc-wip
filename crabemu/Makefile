# $NetBSD: Makefile,v 1.3 2013/03/29 10:52:29 othyro Exp $
#

DISTNAME=	CrabEmu-0.2.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crabemu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crabemu.sourceforge.net/
COMMENT=	Primarily a Sega Master System emulator
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND isc AND public-domain AND zlib AND mame-license AND gnu-lgpl-v2 AND modified-bsd AND original-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_CMAKE=		yes
INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		SDLttf
SUBST_FILES.SDLttf=	src/sdl/config.c
SUBST_MESSAGE.SDLttf=	Fixing FONT_PATH.
SUBST_SED.SDLttf=	-e "s|/usr/share|${BUILDLINK_PREFIX.SDL_ttf}/lib/X11|1"
SUBST_STAGE.SDLttf=	post-patch

.include "options.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
