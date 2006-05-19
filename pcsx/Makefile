# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:29 ykomatsu Exp $
#

DISTNAME=	PcsxSrc-1.5
PKGNAME=	${DISTNAME:S/PcsxSrc/pcsx/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.pcsx.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pcsx.net/
COMMENT=	Free Playstation(TM) emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/Linux

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcsx ${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
