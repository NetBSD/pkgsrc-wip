# $NetBSD: Makefile,v 1.4 2003/09/04 15:38:39 jeremy-c-reed Exp $

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

PKGVER!=	date +%Y%m%d
DIST_SUBDIR=	${PKGNAME}
NO_CHECKSUM=	YES
NO_SRC_ON_FTP=	# defined

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
