# $NetBSD: Makefile,v 1.2 2004/08/22 02:22:39 schnoebe Exp $
# FreeBSD Id: ports/sysutils/copytape/Makefile,v 1.10 2003/02/20 19:00:46 knu Exp

DISTNAME=		copytape
PKGNAME=		copytape-1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_COMP_SOURCES:=unix/volume10/}
EXTRACT_SUFX=		.Z

MAINTAINER=	eric@cirr.com
HOMEPAGE=
COMMENT=	Copytape duplicates magnetic tapes, with only one drive

BUILD_DEPENDS+=	gsharutils>=4.2.1nb2:../../archivers/gsharutils

WRKSRC=			${WRKDIR}

# MASTER_SITES=		${MASTER_SITE_COMP_SOURCES}
# DISTNAME=		copytape
# EXTRACT_SUFX=		.Z

EXTRACT_CMD=            ${GZCAT} ${DOWNLOADED_DISTFILE} | gunshar

MAN1=			copytape.1
MAN5=			copytape.5

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/copytape ${PREFIX}/bin/copytape
	@${INSTALL_MAN} ${WRKSRC}/copytape.1 ${PREFIX}/man/man1/copytape.1
	@${INSTALL_MAN} ${WRKSRC}/copytape.5 ${PREFIX}/man/man5/copytape.5

.include "../../mk/bsd.pkg.mk"

MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources. \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources. \
	ftp://ftp.uu.net/usenet/comp.sources. \
	ftp://ftp.funet.fi/pub/archive/comp.sources. \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.

