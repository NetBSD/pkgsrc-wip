# $NetBSD: Makefile,v 1.1.1.1 2007/06/08 01:10:17 hoka_adam Exp $
#

DISTNAME=	cpdup-1.07
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeSrc/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://apollo.backplane.com/FreeSrc/
COMMENT=	Designed to make exact mirrors of directory trees

WRKSRC=	${WRKDIR}/cpdup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
