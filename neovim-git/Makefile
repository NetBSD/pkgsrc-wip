# $NetBSD: Makefile,v 1.7 2015/06/18 20:53:01 jonthn Exp $

PKGNAME=	neovim-0.5.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}

HOMEPAGE=	http://neovim.org/
COMMENT=	Refactor vim for the 21st century
LICENSE=	vim-license AND apache-2.0

GIT_REPOSITORIES=	neovim
GIT_REPO.neovim=	git://github.com/neovim/neovim.git
GIT_EXTRACTDIR.neovim=	neovim

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/neovim

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo
CMAKE_ARGS+=	-DUSE_BUNDLED=OFF
# busted is only required for testing
CMAKE_ARGS+=	-DBUSTED_PRG=${WRKSRC}/build/busted_luajit_${_LUA_DOT_VERSION}
CMAKE_ARGS+=	-DBUSTED_LUA_PRG=${PREFIX}/bin/busted${_LUA_DOT_VERSION}

# should follow the LuaJIT API compatibility
LUA_VERSIONS_ACCEPTED=	51

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../wip/lua-mpack

post-extract:
	${MKDIR} ${WRKSRC}/build

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../wip/lua-busted
TEST_DEPENDS+=	${LUA_PKGPREFIX}-inspect-[0-9]*:../../wip/lua-inspect
TEST_DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
TEST_DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
TEST_DEPENDS+=	${LUA_PKGPREFIX}-cliargs-[0-9]*:../../wip/lua-cliargs
TEST_DEPENDS+=	${LUA_PKGPREFIX}-term-[0-9]*:../../wip/lua-term
TEST_DEPENDS+=	${LUA_PKGPREFIX}-system-[0-9]*:../../wip/lua-system
TEST_DEPENDS+=	${LUA_PKGPREFIX}-dkjson-[0-9]*:../../wip/lua-dkjson
TEST_DEPENDS+=	${LUA_PKGPREFIX}-say-[0-9]*:../../wip/lua-say
TEST_DEPENDS+=	${LUA_PKGPREFIX}-mediator-[0-9]*:../../wip/lua-mediator
TEST_DEPENDS+=	${LUA_PKGPREFIX}-luassert-[0-9]*:../../wip/lua-luassert
TEST_DEPENDS+=	${LUA_PKGPREFIX}-coxpcall-[0-9]*:../../devel/lua-coxpcall
TEST_DEPENDS+=	${LUA_PKGPREFIX}-luv-[0-9]*:../../wip/lua-luv

pre-test:
	cd ${WRKSRC}/build \
		&& ${SED} \
		-e "s,${PREFIX}/bin/lua${_LUA_DOT_VERSION},${PREFIX}/bin/luajit," \
		${PREFIX}/bin/busted${_LUA_DOT_VERSION} > ${WRKSRC}/build/busted_luajit_${_LUA_DOT_VERSION}
	${CHMOD} +x ${WRKSRC}/build/busted_luajit_${_LUA_DOT_VERSION}

TEST_DIRS=	build
TEST_TARGET=	unittest functionaltest

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/lua/application.mk"
# .include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../wip/LuaJIT21/buildlink3.mk"
# .include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../wip/luv/buildlink3.mk"
.include "../../wip/libunibilium/buildlink3.mk"
.include "../../wip/libtermkey/buildlink3.mk"
.include "../../wip/libvterm/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
