# $NetBSD: Makefile,v 1.4 2010/01/07 07:37:06 thomasklausner Exp $
#

DISTNAME=	cpdup-1.07
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeSrc/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://apollo.backplane.com/FreeSrc/
COMMENT=	Designed to make exact mirrors of directory trees

NOT_FOR_PLATFORM=	${LP64PLATFORMS}

WRKSRC=	${WRKDIR}/cpdup

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
