# $NetBSD: Makefile,v 1.40 2023/07/18 18:19:23 nia Exp $

DISTNAME=	gpick-0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=thezbyg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/thezbyg/gpick/
COMMENT=	Advanced color picker
LICENSE=	modified-bsd

TOOL_DEPENDS+=	ragel-[0-9]*:../../devel/ragel

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config msgfmt msgmerge xgettext

USE_CXX_FEATURES+=	c++14

CMAKE_CONFIGURE_ARGS+=	-DLua_LIBRARIES=-llua${_LUA_DOT_VERSION}
#CXXFLAGS+=	-I${BUILDLINK_DIR}/${LUA_INCDIR}
#LDFLAGS+=	-llua${_LUA_DOT_VERSION}

pre-configure:
	(${ECHO} 0.3; ${ECHO} 0; ${ECHO} 0000000000000000000000000000000000000000; ${ECHO} "May  8, 2022") > ${WRKSRC}/.version

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
