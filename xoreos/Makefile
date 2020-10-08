# $NetBSD: Makefile,v 1.3 2015/09/05 21:49:59 yhardy Exp $

GITHUB_PROJECT=	xoreos
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-0.0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=xoreos/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xoreos/xoreos/
COMMENT=	Open source implementation of BioWare's Aurora engine
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/xoreos-${PKGVERSION_NOREV}
USE_TOOLS+=	aclocal autoconf autoheader automake gmake pkg-config
USE_LIBTOOL=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-release=pkgsrc

INSTALLATION_DIRS+=	bin

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; libtoolize; automake -a --foreign -i; autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xoreos ${DESTDIR}${PREFIX}/bin/

.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
