# $NetBSD$

DISTNAME=	nuspell-3.1.0
CATEGORIES=	textproc wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=nuspell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://nuspell.github.io/
COMMENT=	Free and Open Source C++ spell checking library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++17

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1 -DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DRONN_EXECUTABLE=${PREFIX}/bin/ronn${RUBY_VER}

PKGCONFIG_OVERRIDE+=	nuspell.pc.in

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-ronn-[0-9]*:../../devel/ruby-ronn

.include "../../lang/ruby/rubyversion.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
