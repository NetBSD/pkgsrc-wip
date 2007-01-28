# $NetBSD: Makefile,v 1.1 2007/01/28 12:23:38 corecode Exp $

# First paragraph - distfile and binary package data
# DISTNAME PKGNAME PKGREVISION SVR4_PKGNAME CATEGORIES MASTER_SITES
# MASTER_SITE_SUBDIR EXTRACT_SUFX DISTFILES
PKGNAME=		mp3gain-1.4.6
DISTNAME=		${PKGNAME:S/./_/g}-src
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3gain/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mp3gain.sourceforge.net/
COMMENT=		Loudness normalizer for MP3 files

WRKSRC=			${WRKDIR}

EXTRACT_OPTS_ZIP=	-aqo
MAKE_ENV+=		${BSD_MAKE_ENV}

.include "../../mk/bsd.prefs.mk"

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
