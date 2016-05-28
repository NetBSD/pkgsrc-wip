# $NetBSD: Makefile,v 1.9 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=		postal2mpdemo-lnx-1407
PKGNAME=		postal2-mpdemo-bin-0
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		http://files3.worthplaying.com/postal2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://files3.worthplaying.com/postal2/
COMMENT=		Demo of a violent 3D game
LICENSE=		postal2mpdemo-license

RESTRICTED=		It's huge, it's demo, it's a game, I'm not sure if we can redistribute it
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_PKG_ON_CDROM=	${RESTRICTED}


EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	glx
SUSE_VERSION_REQD=	7.3

# Would install outside of ${LOCALBASE} on Linux.
NOT_FOR_PLATFORM=	Linux-*-*

NO_BUILD=		yes

POSTAL_DIR=		${EMULDIR}/usr/games/postal

do-install:
	cd ${WRKSRC} && ./postal2mpdemo-lnx-1407.run --target ${WRKSRC}/tmp \
		--nox11 -- --help
	${INSTALL_DATA_DIR} ${POSTAL_DIR}
	cd ${POSTAL_DIR} && ${TAR} -xvf ${WRKSRC}/tmp/postal2mpdemo.tar
	cd ${POSTAL_DIR} && ${TAR} -xvf ${WRKSRC}/tmp/linux-specific.tar

.include "../../mk/bsd.pkg.mk"
