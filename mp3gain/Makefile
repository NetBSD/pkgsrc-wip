# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:57 asau Exp $

PKGNAME=		mp3gain-1.4.6
DISTNAME=		${PKGNAME:S/./_/g}-src
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3gain/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mp3gain.sourceforge.net/
COMMENT=		Loudness normalizer for MP3 files

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}

MAKE_ENV+=		${BSD_MAKE_ENV}

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
