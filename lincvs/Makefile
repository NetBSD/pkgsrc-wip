# $NetBSD: Makefile,v 1.2 2003/12/29 03:06:20 mpasternak Exp $
#

DISTNAME=		lincvs-1.3.0-rc2-generic-src
PKGNAME=		${DISTNAME:S/-rc2-generic-src//}
WRKSRC=			${WRKDIR}/${PKGNAME}-rc2
CATEGORIES=		devel x11
MASTER_SITES=	        http://ppprs1.phy.tu-dresden.de/~trogisch/lincvs/download/20_LinCVS/hr_lincvs-1.3.0rc2/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.lincvs.org/
COMMENT=		Nice GUI front-end to CVS (using Qt)

USE_BUILDLINK2=		YES

pre-build:
	 ${QTDIR}/bin/qmake -o ${WRKSRC}/Makefile ${WRKSRC}/lincvs.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lincvs.bin ${PREFIX}/bin/lincvs

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
