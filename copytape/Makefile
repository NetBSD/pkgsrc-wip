# $NetBSD: Makefile,v 1.4 2004/12/02 16:38:57 thomasklausner Exp $
# FreeBSD Id: ports/sysutils/copytape/Makefile,v 1.10 2003/02/20 19:00:46 knu Exp

DISTNAME=		copytape
PKGNAME=		${DISTNAME}-1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_COMP_SOURCES:=unix/volume10/}
EXTRACT_SUFX=		.Z

MAINTAINER=	eric@cirr.com
HOMEPAGE=
COMMENT=	Copytape duplicates magnetic tapes, with only one drive

BUILD_DEPENDS+=	gsharutils>=4.2.1nb2:../../archivers/gsharutils

WRKSRC=			${WRKDIR}
BUILD_TARGET=		copytape

# MASTER_SITES=		${MASTER_SITE_COMP_SOURCES}
# DISTNAME=		copytape
# EXTRACT_SUFX=		.Z

EXTRACT_CMD=            ${GZCAT} ${DOWNLOADED_DISTFILE} | ${PREFIX}/bin/${GNU_PROGRAM_PREFIX}unshar

# post-fetch:
# 	${MV} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
# 				${DISTDIR}/${DISTNAME}.shar${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/copytape ${PREFIX}/bin/copytape
	${INSTALL_MAN} ${WRKSRC}/copytape.1 ${PREFIX}/man/man1/copytape.1
	${INSTALL_MAN} ${WRKSRC}/copytape.5 ${PREFIX}/man/man5/copytape.5

.include "../../mk/bsd.pkg.mk"

MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources. \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources. \
	ftp://ftp.uu.net/usenet/comp.sources. \
	ftp://ftp.funet.fi/pub/archive/comp.sources. \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.

