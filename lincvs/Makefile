# $NetBSD: Makefile,v 1.1.1.1 2003/08/28 23:38:15 mpasternak Exp $
#

DISTNAME=		lincvs-1.2.0-0-generic-src
PKGNAME=		${DISTNAME:S/-0-generic-src//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		devel x11
MASTER_SITES=		http://ppprs1.phy.tu-dresden.de/~trogisch/lincvs/download/LinCVS/lincvs-1.2.0/
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
