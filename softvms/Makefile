# $NetBSD$

PKGNAME=	softvms-1.9
DISTNAME=	softvms
CATEGORIES=	emulators
MASTER_SITES=	https://mc.pp.se/dc/files/
MASTER_SITE_BACKUP=	https://travispaul.me/distfiles/

MAINTAINER=	tr@vispaul.me
HOMEPAGE=	https://mc.pp.se/dc/sw.html
COMMENT=	Emulator capable of running some VMS games
LICENSE=	mit

WRKSRC=		${WRKDIR}/vms
GNU_CONFIGURE=	yes
BUILD_TARGET=	vms
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms ${DESTDIR}${PREFIX}/bin/vms

.include "../../x11/libX11/buildlink3.mk"

.include "../../audio/SDL_sound/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"


