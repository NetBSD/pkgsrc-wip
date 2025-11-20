# $NetBSD$

DISTNAME=	nheko-0.12.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nheko-Reborn/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nheko-Reborn/nheko/
COMMENT=	Native desktop app for Matrix chat protocol
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_CXX_FEATURES+=	c++20
USE_LANGUAGES=		c c++
USE_TOOLS=		cmake pkg-config

CMAKE_CONFIGURE_ARGS+=	-DVOIP=OFF
CMAKE_CONFIGURE_ARGS+=	-DSCREENSHARE_X11=OFF

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

.include "../../devel/cmake/build.mk"

.include "../../databases/lmdb/buildlink3.mk"
USE_BUILTIN.libevent=	no
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../security/olm/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../wip/coeurl/buildlink3.mk"
.include "../../wip/kdsingleapplication/buildlink3.mk"
.include "../../wip/lmdbxx/buildlink3.mk"
.include "../../wip/mtxclient/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
