# $NetBSD: Makefile,v 1.6 2013/01/03 21:21:36 mrampke Exp $
#

DISTNAME=	cpdup-1.17
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeSrc/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	matthias@rampke.de
HOMEPAGE=	http://apollo.backplane.com/FreeSrc/
COMMENT=	Designed to make exact mirrors of directory trees

LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/cpdup

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/libbsd/buildlink3.mk"

# on platforms where libbsd is available, it is needed for MD5
.if defined(USE_LIBBSD)
MAKE_FLAGS+= -DLIBBSD
.elif ${OS} == Darwin
MAKE_FLAGS+= -DNOMD5
.endif

.include "../../mk/bsd.pkg.mk"
