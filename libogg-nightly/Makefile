# $NetBSD: Makefile,v 1.8 2004/02/17 02:56:01 blef Exp $

DISTNAME=	vorbis_nightly_cvs
PKGNAME=	libogg-${PKGVER}
WRKSRC=		${WRKDIR}/ogg
CATEGORIES=	audio devel
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library (nightly source)

CONFLICTS=	libogg-[0-9]*

.include "../../mk/bsd.prefs.mk"

PKGVER!=	${DATE} +%Y%m%d
# This distfile is shared with libvorbis-nightly
DIST_SUBDIR=	 ${DISTNAME}-${PKGVER}
NO_CHECKSUM=	YES
NO_SRC_ON_FTP=	# defined

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
