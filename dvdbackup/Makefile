# $NetBSD: Makefile,v 1.1.1.1 2004/01/12 06:13:30 marttikuparinen Exp $

DISTNAME=	dvdbackup-0.1.1
WRKSRC=		${WRKDIR}/dvdbackup/src
CATEGORIES=	sysutils
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD-Video backup utility

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvdbackup ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvdbackup
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dvdbackup

.include "../../misc/libdvdcss/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
