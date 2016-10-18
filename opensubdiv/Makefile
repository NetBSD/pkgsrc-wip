# $NetBSD$

GITHUB_PROJECT=	OpenSubdiv
DISTNAME=	OpenSubdiv-3.1.0.RC2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=PixarAnimationStudios/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./_/g:tu}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://graphics.pixar.com/opensubdiv/docs/intro.html
COMMENT=	High performance subdivision surface for parallel architectures
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# Useless and installs files by default into subdirs of $PREFIX/bin/
CMAKE_ARGS+=	-DNO_TUTORIALS:BOOL=ON

# TODO
CMAKE_ARGS+=	-DNO_OPENCL:BOOL=ON
CMAKE_ARGS+=	-DNO_CUDA:BOOL=ON

TEST_TARGET=	test

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
