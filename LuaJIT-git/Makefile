# $NetBSD$

DISTNAME=	LuaJIT-git-2.1
CATEGORIES=	lang

GIT_REPO=	https://luajit.org/git/luajit.git
GIT_BRANCH=	v2.1

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

CONFLICTS+=	LuaJIT2-[0-9]* LuaJIT21-[0-9]*

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	*-*-aarch64*
ONLY_FOR_PLATFORM+=	*-*-*arm*	# ARMv5+, ARM9E+
ONLY_FOR_PLATFORM+=	*-*-i386	# req SSE2
ONLY_FOR_PLATFORM+=	*-*-mips*
ONLY_FOR_PLATFORM+=	*-*-powerpc
ONLY_FOR_PLATFORM+=	*-*-x86_64

# pkg/47587: lua not linked to pthread causes issues with modules
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
