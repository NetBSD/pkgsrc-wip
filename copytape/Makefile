# $NetBSD: Makefile,v 1.11 2012/09/24 17:51:30 asau Exp $

DISTNAME=		copytape
PKGNAME=		${DISTNAME}-1.0
CATEGORIES=		sysutils
MASTER_SITES= \
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.unix/volume10/ \
	ftp://ftp.uu.net/usenet/comp.sources.unix/volume10/ \
	ftp://ftp.funet.fi/pub/archive/comp.sources.unix/volume10/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.unix/volume10/
EXTRACT_SUFX=		.Z

MAINTAINER=	eric@cirr.com
COMMENT=	Copytape duplicates magnetic tapes, with only one drive

BUILD_DEPENDS+=	gsharutils>=4.2.1nb2:../../archivers/gsharutils

WRKSRC=			${WRKDIR}
BUILD_TARGET=		copytape

EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${PREFIX}/bin/gunshar

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/copytape ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/copytape.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/copytape.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
