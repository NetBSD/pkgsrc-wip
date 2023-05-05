# $NetBSD: Makefile,v 1.6 2023/04/25 23:36:19 nikita Exp $

DISTNAME=	neovim-0.10.0.9ded4c1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_TAG=	9ded4c127599b821d0875db9d63049b5970437a4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/neovim/
COMMENT=	Vim fork focused on extensibility and usability
LICENSE=	apache-2.0 AND vim-license

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config xgettext

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DLIBVTERM_LIBRARY=${BUILDLINK_PREFIX.libvterm03}/lib/libvterm03/libvterm.so
CMAKE_ARGS+=	-DLIBVTERM_INCLUDE_DIR=${BUILDLINK_PREFIX.libvterm03}/include/libvterm03

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

LDFLAGS.SunOS+=		-lrt

# should follow the LuaJIT API compatibility
LUA_VERSIONS_ACCEPTED=	51

# https://github.com/neovim/neovim/issues/223#issuecomment-374763255
# FORTIFY_SUPPORTED=	no

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../devel/lua-mpack
DEPENDS+=	${LUA_PKGPREFIX}-luv-[0-9]*:../../devel/lua-luv
DEPENDS+=	${LUA_PKGPREFIX}-inspect-[0-9]*:../../devel/lua-inspect
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp
TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

post-extract:
	${MKDIR} ${WRKDIR}/build

post-install:
	# https://github.com/neovim/neovim/issues/23395
	# lpeg ends up as full path in NEEDED, rpath part
	# of it is missing.
	# official fix seems to be to build a vendored lpeg.
	${PREFIX}/bin/patchelf --replace-needed \
		"${PREFIX}/lib/lua/5.1/lpeg.so" lpeg.so \
		${DESTDIR}${PREFIX}/bin/nvim
	${PREFIX}/bin/patchelf ${DESTDIR}${PREFIX}/bin/nvim \
		--add-rpath ${PREFIX}/lib/lua/5.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.if ${OPSYS} == "SunOS"
.  include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libtermkey/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/libvterm03/buildlink3.mk"
.include "../../devel/lua-luv/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../devel/unibilium/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/LuaJIT2/platform.mk"
.if ${PLATFORM_SUPPORTS_LUAJIT:tl} == "yes"
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DPREFER_LUA=ON
.  include "../../lang/lua51/buildlink3.mk"
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/tree-sitter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
