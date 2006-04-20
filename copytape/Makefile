# $NetBSD: Makefile,v 1.7 2006/04/20 13:36:35 cheusov Exp $

DISTNAME=		copytape
PKGNAME=		${DISTNAME}-1.0
CATEGORIES=		sysutils
MASTER_SITES= \
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.unix/volume10/ \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources.unix/volume10/ \
	ftp://ftp.uu.net/usenet/comp.sources.unix/volume10/ \
	ftp://ftp.funet.fi/pub/archive/comp.sources.unix/volume10/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.unix/volume10/
EXTRACT_SUFX=		.Z

MAINTAINER=	eric@cirr.com
COMMENT=	Copytape duplicates magnetic tapes, with only one drive

BUILD_DEPENDS+=	gsharutils>=4.2.1nb2:../../archivers/gsharutils

WRKSRC=			${WRKDIR}
BUILD_TARGET=		copytape

EXTRACT_CMD=            ${GZCAT} ${DOWNLOADED_DISTFILE} | ${PREFIX}/bin/${GNU_PROGRAM_PREFIX}unshar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/copytape ${PREFIX}/bin/copytape
	${INSTALL_MAN} ${WRKSRC}/copytape.1 ${PREFIX}/${PKGMANDIR}/man1/copytape.1
	${INSTALL_MAN} ${WRKSRC}/copytape.5 ${PREFIX}/${PKGMANDIR}/man5/copytape.5

.include "../../mk/bsd.pkg.mk"
