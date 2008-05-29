# $NetBSD: Makefile,v 1.3 2008/05/29 18:01:17 tnn2 Exp $
#

DISTNAME=	cpdup-1.07
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeSrc/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://apollo.backplane.com/FreeSrc/
COMMENT=	Designed to make exact mirrors of directory trees

NOT_FOR_PLATFORM=	*-*-x86_64 *-*-alpha *-*-sparc64

WRKSRC=	${WRKDIR}/cpdup

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
