# $NetBSD: Makefile,v 1.1.1.1 2003/05/23 02:17:46 jeremy-c-reed Exp $

DISTNAME=	theora_cvs_snapshot
PKGNAME=	theora-${PKGVER}
WRKSRC=		${WRKDIR}/theora
CATEGORIES=	graphics
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.theora.org/
COMMENT=	video codec for Ogg multimedia streaming (nightly binary pkg)

PKGVER!=	date +%Y%m%d

DIST_SUBDIR=	${PKGNAME}
NO_CHECKSUM=	# defined

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

# XXX the Makefile's don't install examples yet
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/encoder_example ${PREFIX}/bin/theora-encoder_example
	${INSTALL_PROGRAM} ${WRKSRC}/examples/player_example ${PREFIX}/bin/theora-player_example
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/theora
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/theora/

# XXX SDL is for the player_example
.include "../../devel/SDL/buildlink2.mk"

# XXX use the latest libvorbis (and libogg too)
BUILDLINK_DEPENDS.libvorbis=   libvorbis>=20030520
BUILDLINK_PKGSRCDIR.libvorbis= ../../audio/libvorbis-nightly
.include "../../audio/libvorbis/buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
