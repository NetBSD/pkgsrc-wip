# $NetBSD: Makefile,v 1.9 2004/02/17 02:56:01 blef Exp $

DISTNAME=		vorbis_nightly_cvs
PKGNAME=		libvorbis-${PKGVER}
WRKSRC=			${WRKDIR}/vorbis
CATEGORIES=		audio devel
MASTER_SITES=		http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.xiph.org/ogg/vorbis/
COMMENT=		Library for the Ogg Vorbis audio encoding format (nightly source)

CONFLICTS=		libvorbis-[0-9]*

.include "../../mk/bsd.prefs.mk"

PKGVER!=		${DATE} +%Y%m%d
# This distfile is shared with libogg-nightly
DIST_SUBDIR=		${DISTNAME}-${PKGVER}
NO_CHECKSUM=		YES
NO_SRC_ON_FTP=		# defined

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

# XXX use latest libogg too
BUILDLINK_DEPENDS.libogg=	libogg>=20030520
BUILDLINK_PKGSRCDIR.libogg=	../../wip/libogg-nightly
.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
