# $NetBSD: Makefile,v 1.5 2003/09/04 15:38:39 jeremy-c-reed Exp $

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

PKGVER!=		date +%Y%m%d
DIST_SUBDIR=		${PKGNAME}
NO_CHECKSUM=		YES
NO_SRC_ON_FTP=		# defined

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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
