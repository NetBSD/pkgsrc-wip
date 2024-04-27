# $NetBSD$

DISTNAME=	sdl-sopwith-2.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fragglet/}
GITHUB_TAG=	${DISTNAME}
GITHUB_PROJECT=	sdl-sopwith
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fragglet/sdl-sopwith
COMMENT=	Classic biplane shoot-'em up
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c99
# GNU make is required for man page generation (broken with BSD make)
USE_TOOLS+=		autoconf automake gmake pkg-config autoreconf
GNU_CONFIGURE=		yes

PLIST.bsd=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

BUILDLINK_API_DEPENDS.SDL2+=		SDL2>=2.0.7
.include "../../devel/SDL2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
