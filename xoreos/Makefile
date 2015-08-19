# $NetBSD: Makefile,v 1.1 2015/08/19 20:07:05 yhardy Exp $

GITHUB_PROJECT=	xoreos
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-0.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=xoreos/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=xoreos/xoreos/}
COMMENT=	Open source implementation of BioWare's Aurora engine
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/xoreos-0.0.2
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DFAAD_INCLUDE_DIR=${PREFIX}/include/faad2
CMAKE_ARGS+=	-DSDL2_INCLUDE_DIR=${PREFIX}/include/SDL2


INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xoreos ${DESTDIR}${PREFIX}/bin/

.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
