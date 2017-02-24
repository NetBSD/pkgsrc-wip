# $NetBSD$

PKGNAME=	luv-${GIT_TAG.luv:S/-/./g}
CATEGORIES=	devel
LICENSE=	apache-2.0

GIT_REPOSITORIES+=	luv
GIT_REPO.luv=		https://github.com/luvit/luv.git
GIT_TAG.luv=		1.9.1-1

COMMENT=	Bare libuv bindings for Lua
MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/luvit/luv/

USE_CMAKE=	yes

WRKSRC=	${WRKDIR}/luv

.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
