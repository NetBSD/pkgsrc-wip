# $NetBSD: Makefile,v 1.9 2010/06/13 22:47:13 thomasklausner Exp $
#

DISTNAME=	PcsxSrc-1.5
PKGNAME=	${DISTNAME:S/PcsxSrc/pcsx/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.pcsx.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pcsx.net/
COMMENT=	Free Playstation(TM) emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/Linux

# Build fails with GCC4
#
USE_PKGSRC_GCC=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcsx ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
