# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:43 tvierling Exp $
#

DISTNAME=	PcsxSrc-1.5
PKGNAME=	${DISTNAME:S/PcsxSrc/pcsx/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.pcsx.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pcsx.net/
COMMENT=	Free Playstation(TM) emulator

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Linux

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcsx ${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
