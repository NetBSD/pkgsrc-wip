# $NetBSD$

DISTNAME=	whisper.cpp-1.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggerganov/}
GITHUB_PROJECT=	whisper.cpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/whisper.cpp/
COMMENT=	OpenAI's Whisper LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		git pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

PKGCONFIG_OVERRIDE+=	cmake/parakeet.pc.in
PKGCONFIG_OVERRIDE+=	cmake/whisper.pc.in
REPLACE_PYTHON+=	*/*.py */*/*.py

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_BUILD_SERVER=ON
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_BUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_COMMON_FFMPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_SDL2=OFF
CMAKE_CONFIGURE_ARGS+=	-DWHISPER_USE_SYSTEM_GGML=ON

#.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../wip/llama.cpp/buildlink3.mk"
.include "../../wip/ggml/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
