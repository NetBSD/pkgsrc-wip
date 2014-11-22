# $NetBSD: Makefile,v 1.1 2014/11/22 22:58:46 jonthn Exp $

PKGNAME=	neovim-0.0.0
CATEGORIES=	editors
MASTER_SITES=	https://github.com/neovim/neovim/archive/

HOMEPAGE=	http://neovim.org/
COMMENT=	Refactor vim for the 21st century
LICENSE=	vim-license AND apache-2.0

GIT_REPOSITORIES=	neovim
GIT_REPO.neovim=	git://github.com/neovim/neovim.git
GIT_MODULE.neovim=	neovim
WRKSRC=			${WRKDIR}/${GIT_MODULE.neovim}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

DEPENDS+=       ${LUA_PKGPREFIX}-MessagePack:../../wip/lua-MessagePack
DEPENDS+=       ${LUA_PKGPREFIX}-lpeg:../../devel/lua-lpeg
DEPENDS+=       lua51-MessagePack:../../wip/lua-MessagePack
DEPENDS+=       lua51-lpeg:../../devel/lua-lpeg

.include "../../wip/libuv0.11/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/msgpack-git/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/lua/application.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
