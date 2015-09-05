# $NetBSD: Makefile,v 1.2 2015/09/05 16:05:10 yhardy Exp $

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
USE_TOOLS+=	aclocal autoconf autoheader automake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

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
.include "../../audio/openal/buildlink3.mk"
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
