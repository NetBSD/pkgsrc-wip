# $NetBSD$

DISTNAME=	OpenSubdiv-3.5.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=PixarAnimationStudios/}
GITHUB_PROJECT=	OpenSubdiv
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./_/g:tu}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://graphics.pixar.com/opensubdiv/docs/intro.html
COMMENT=	High performance subdivision surface for parallel architectures
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# Useless and installs files by default into subdirs of $PREFIX/bin/
CMAKE_CONFIGURE_ARGS+=	-DNO_TUTORIALS:BOOL=ON

# TODO
CMAKE_CONFIGURE_ARGS+=	-DNO_OPENCL:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DNO_CUDA:BOOL=ON

TEST_TARGET=	test

.include "options.mk"

.include "../../parallel/threadingbuildingblocks/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
