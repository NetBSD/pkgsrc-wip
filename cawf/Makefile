# $NetBSD: Makefile,v 1.2 2004/08/18 13:42:45 rillig Exp $

DISTNAME=	cawf
PKGNAME=	cawf-4.10
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://vic.cc.purdue.edu/pub/
MASTER_SITES+=	http://www.tux.org/pub/sites/vic.cc.purdue.edu/
EXTRACT_SUFX=	.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	ftp://vic.cc.purdue.edu/pub/cawf.README
COMMENT=	nroff-like text formatter

CAWFLIB=	${PREFIX}/share/cawf
PLIST_SUBST+=   CAWFLIB=share/cawf
BUILD_DEFS+=	CAWFLIB
MAKE_FLAGS+=	CAWFLIB=${CAWFLIB}

post-extract:
	${MV} ${WRKSRC}/cawf.1 ${WRKSRC}/cawf.1.orig && \
	${SED} -e "s|/Homes/abe/lib/cawf|${CAWFLIB}|g" \
		< ${WRKSRC}/cawf.1.orig > ${WRKSRC}/cawf.1

do-install:
	${INSTALL_DATA_DIR} ${CAWFLIB}
	${INSTALL_DATA}	${WRKSRC}/common ${CAWFLIB}
	${INSTALL_DATA}	${WRKSRC}/device.cf ${CAWFLIB}
	${INSTALL_DATA}	${WRKSRC}/dumb.dev ${CAWFLIB}
	${INSTALL_DATA}	${WRKSRC}/man.mac ${CAWFLIB}
	${INSTALL_DATA}	${WRKSRC}/me.mac ${CAWFLIB}
	${INSTALL_DATA}	${WRKSRC}/ms.mac ${CAWFLIB}
	${INSTALL_PROGRAM} ${WRKSRC}/cawf ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bsfilt ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cawf.1 ${PREFIX}/man/man1/cawf.1
	${INSTALL_MAN} ${WRKSRC}/bsfilt.1 ${PREFIX}/man/man1/bsfilt.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cawf
	${INSTALL_DATA} ${WRKSRC}/00readme ${PREFIX}/share/doc/cawf/README
	${INSTALL_DATA} ${WRKSRC}/00diffs ${PREFIX}/share/doc/cawf/roff-differences.txt

.include "../../mk/bsd.pkg.mk"
