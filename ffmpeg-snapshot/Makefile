# $NetBSD: Makefile,v 1.1.1.1 2006/12/12 01:52:57 cetrox Exp $
#

DISTNAME=	ffmpeg-export-snapshot
PKGNAME=	ffmpeg-snapshot-${VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	http://ffmpeg.mplayerhq.hu/
EXTRACT_SUFX=	.tar.bz2

.include "../../mk/bsd.prefs.mk"
VERSION!=	${DATE} +%Y%m%d
DATEDIR!=	${DATE} +%Y-%m-%d
SRCDIR=		ffmpeg-export-${DATEDIR}

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Nightly snapshot of the ffmpeg tool

WRKSRC=		${WRKDIR}/${SRCDIR}
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-memalign-hack
CONFIGURE_ARGS+=	--cpu=i686

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake


# Checking if distfile is recent.
pre-extract:
	@if [ -f ${DISTDIR}/${DISTFILES} ]; then \
	  if [ "`tar ztf ${DISTDIR}/${DISTFILES} 2> /dev/null | \
		head -1`" = ${SRCDIR} ]; then \
		echo lala; \
	  else \
		${ECHO} "Please cleandir and fetch distfile again." ; \
	  fi \
	fi

.include "../../mk/bsd.pkg.mk"
