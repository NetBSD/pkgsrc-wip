# $NetBSD$

DISTNAME=	softvms
PKGNAME=	softvms-1.9
CATEGORIES=	emulators
MASTER_SITES=	http://mc.pp.se/dc/files/
MASTER_SITES+=	https://travispaul.me/distfiles/

MAINTAINER=	tr@vispaul.me
HOMEPAGE=	http://mc.pp.se/dc/sw.html
COMMENT=	Emulator capable of running some Sega VMS games
LICENSE=	mit

WRKSRC=			${WRKDIR}/vms
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

BUILD_TARGET=		vms

.include "../../x11/libX11/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms ${DESTDIR}${PREFIX}/bin/vms

.include "../../mk/bsd.pkg.mk"
