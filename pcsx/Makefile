# $NetBSD: Makefile,v 1.7 2008/03/09 01:05:18 hoka_adam Exp $
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

# Build fails with GCC4
#
USE_PKGSRC_GCC=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcsx ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
