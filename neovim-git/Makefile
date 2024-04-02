# $NetBSD$

PKGNAME=	neovim-git-0.10.0
CATEGORIES=	editors

GIT_REPO=	https://github.com/neovim/neovim.git
GIT_BRANCH=	master

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	http://neovim.org/
COMMENT=	Vim fork focused on extensibility and usability
LICENSE=	vim-license AND apache-2.0

CONFLICTS+=	neovim-[0-9]*

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config gettext

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo
CMAKE_CONFIGURE_ARGS+=	-DUSE_BUNDLED=OFF
CMAKE_CONFIGURE_ARGS+=	-DLIBVTERM_LIBRARY=${BUILDLINK_PREFIX.libvterm03}/lib/libvterm03/libvterm.so
CMAKE_CONFIGURE_ARGS+=	-DLIBVTERM_INCLUDE_DIR=${BUILDLINK_PREFIX.libvterm03}/include/libvterm03

LUA_VERSIONS_ACCEPTED=	51

DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-inspect-[0-9]*:../../devel/lua-inspect
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../devel/lua-mpack

TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

post-install:
	${PREFIX}/bin/patchelf ${DESTDIR}${PREFIX}/bin/nvim \
		--replace-needed ${PREFIX}/lib/lua/5.1/lpeg.so lpeg.so
	${PREFIX}/bin/patchelf ${DESTDIR}${PREFIX}/bin/nvim \
		--add-rpath ${PREFIX}/lib/lua/5.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/lua-luv/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../devel/unibilium/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../textproc/tree-sitter/buildlink3.mk"
.include "../../wip/LuaJIT-git/platform.mk"
.if ${PLATFORM_SUPPORTS_LUAJIT:tl} == "yes"
.  include "../../wip/LuaJIT-git/buildlink3.mk"		# XXX: req v2.1
.else
CMAKE_CONFIGURE_ARGS+=	-DPREFER_LUA=ON
.  include "../../lang/lua/buildlink3.mk"
.endif
.include "../../wip/libvterm03/buildlink3.mk"		# XXX: req v0.3.3
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
