# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:58 asau Exp $
#

DISTNAME=	mplabs-1.1
CATEGORIES=	math
MASTER_SITES=	http://mplabs.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/mplabs/
COMMENT=	Multiphase lattice boltzmann suite
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/mplabs

USE_LANGUAGES=	fortran

INSTALLATION_DIRS+=	bin share/doc/mplabs

do-build:
	cd ${WRKSRC} && ${SH} install.sh

do-install:
.for i in LL-2D-DGR      LL-2D-STD      ZSC-2D-DGR     ZSC-2D-STD
	${INSTALL_DATA} ${WRKSRC}/bin/${i} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/mp-labs.pdf \
		${DESTDIR}${PREFIX}/share/doc/mplabs

.include "../../parallel/openmpi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
