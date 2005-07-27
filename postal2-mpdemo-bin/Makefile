# $NetBSD: Makefile,v 1.3 2005/07/27 16:26:45 thomasklausner Exp $
#

DISTNAME=		postal2mpdemo-lnx-1407
PKGNAME=		postal2-mpdemo-bin-0
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		http://files3.worthplaying.com/postal2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://files3.worthplaying.com/postal2/
COMMENT=		Demo of a violent 3D game

DEPENDS+=		suse_glx>=7.3:../../emulators/suse_glx/

NO_SRC_ON_CDROM=	"It's huge, it's demo, it's a game, I'm not sure if we can redistribute it"
NO_PKG_ON_CDROM=	${NO_SRC_ON_CDROM}
NO_BUILD=		# defined
LICENSE=		postal2mpdemo-license

POSTAL_DIR=		${PREFIX}/emul/linux/usr/games/postal

do-install:
	cd ${WRKSRC} && ./postal2mpdemo-lnx-1407.run --target ${WRKSRC}/tmp \
		--nox11 -- --help
	${INSTALL_DATA_DIR} ${POSTAL_DIR}
	cd ${POSTAL_DIR} && ${TAR} -xvf ${WRKSRC}/tmp/postal2mpdemo.tar
	cd ${POSTAL_DIR} && ${TAR} -xvf ${WRKSRC}/tmp/linux-specific.tar

.include "../../mk/bsd.pkg.mk"
