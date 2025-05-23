# $NetBSD: Makefile,v 1.108 2025/01/10 22:49:54 wiz Exp $

V=		9.0.2
DISTNAME=	kicad-${V}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/code/}
GITLAB_PROJECT=	kicad
GITLAB_RELEASE=	${V}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Schematic and PCB CAD software (stable branch)
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	swig4-[0-9]*:../../devel/swig4
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	charconv filesystem c++17
USE_TOOLS+=		pkg-config msgfmt msgmerge xgettext

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=		-DKICAD_SCRIPTING_WXPYTHON=OFF
CMAKE_CONFIGURE_ARGS+=		-DKICAD_BUILD_I18N=ON

# KICAD_USE_EGL must be defined if wxWidgets was compiled with EGL canvas.
.include "../../graphics/MesaLib/features.mk"
.if !empty(MESALIB_SUPPORTS_EGL:Myes)
CMAKE_CONFIGURE_ARGS+=		-DKICAD_USE_EGL=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DKICAD_USE_EGL=OFF
.endif

#SUBST_CLASSES+=		undef
#SUBST_STAGE.undef=	post-configure
#SUBST_MESSAGE.undef=    TODO: Conflict 'major' and 'minor' defined somewhere.
#SUBST_FILES.undef=	cmake-pkgsrc-build/api/cpp/api/common/types/base_types.pb.h
#SUBST_SED.undef=	-e "/^#include <string>$/a #undef major"
#SUBST_SED.undef+=	-e "/^#include <string>$/a #undef minor"
USE_CXX_FEATURES=	c++17

PY_PATCHPLIST=		yes

# The package tries to build a native .app bundle. This doesn't work
# in pkgsrc context because they don't support DESTDIR installation,
# which is a requirement in pkgsrc. It also tries to use native Python
# frameworks, but has to use pkgsrc's. Getting this to build requires 15
# additional patches. Ping if you you want the patches.
# I didn't commit them yet because it segfaults. -tnn 20220102
NOT_FOR_PLATFORM+=	Darwin-*-*

.include "options.mk"

# needs 64-bit CAS for std::atomic<size_t>
.include "../../mk/atomic64.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../cad/occt/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
BUILDLINK_API_DEPENDS.glm+=	glm>=0.9.9.8
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../net/nng/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
