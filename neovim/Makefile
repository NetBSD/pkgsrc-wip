# $NetBSD$

DISTNAME=	neovim-0.6.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/neovim/
COMMENT=	Vim-fork focused on extensibility and usability
LICENSE=	apache-2.0 AND vim-license

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARG_PATH=		${WRKSRC}

LDFLAGS.SunOS+=		-lrt

# should follow the LuaJIT API compatibility
LUA_VERSION_REQD=	51

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../wip/lua-mpack
DEPENDS+=	${LUA_PKGPREFIX}-luv-[0-9]*:../../wip/lua-luv
DEPENDS+=	${LUA_PKGPREFIX}-inspect-[0-9]*:../../devel/lua-inspect
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp

# https://github.com/neovim/neovim/issues/223#issuecomment-374763255
FORTIFY_SUPPORTED=	no

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/msgpack/buildlink3.mk"
# Only use luajit whenever it is supported by the current architecture,
# fall back on plain lua if not.
#
# In addition, LuaJIT does not play well on x86_64 SunOS where memory
# allocations fails.
.if ${OPSYS} == "SunOS"
    || (!empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Msparc) || !empty(MACHINE_ARCH:Msparc64))
.include "../../lang/lua51/buildlink3.mk"
CMAKE_ARGS+=		-DPREFER_LUA=ON
.else
.include "../../lang/LuaJIT2/buildlink3.mk"
.endif
.include "../../lang/lua/application.mk"
.include "../../wip/lua-luv/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/tree-sitter/buildlink3.mk"
.include "../../wip/libtermkey/buildlink3.mk"
.include "../../wip/libunibilium/buildlink3.mk"
.include "../../wip/libvterm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
