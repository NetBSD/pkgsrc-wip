# $NetBSD: Makefile,v 1.7 2015/06/18 20:53:01 jonthn Exp $

PKGNAME=	neovim-0.2.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}

HOMEPAGE=	http://neovim.org/
COMMENT=	Refactor vim for the 21st century
LICENSE=	vim-license AND apache-2.0

GIT_REPOSITORIES=	neovim
GIT_REPO.neovim=	git://github.com/neovim/neovim.git
GIT_MODULE.neovim=	neovim
WRKSRC=			${WRKDIR}/${GIT_MODULE.neovim}

# should follow the LuaJIT API compatibility
LUA_VERSIONS_ACCEPTED=	51

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo

DEPENDS+=	${LUA_PKGPREFIX}-MessagePack-[0-9]*:../../wip/lua-MessagePack
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../wip/lua-mpack

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "options.mk"

.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/lua/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/libunibilium/buildlink3.mk"
.include "../../wip/libtermkey/buildlink3.mk"
.include "../../wip/libvterm/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
