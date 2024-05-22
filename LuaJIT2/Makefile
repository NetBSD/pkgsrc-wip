# $NetBSD$

DISTNAME=	LuaJIT-2.0.1713483859	# see .relver
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT2/}
CATEGORIES=	lang lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=LuaJIT/}
GITHUB_PROJECT=	${DISTNAME:C/-[^-]*$//}
GITHUB_TAG=	9b5e837ac2dfdc0638830c048a47ca9378c504d3

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

CONFLICTS+=	LuaJIT21-[0-9]* LuaJIT-git-[0-9]*

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	*-*-*arm*
ONLY_FOR_PLATFORM+=	*-*-i386
ONLY_FOR_PLATFORM+=	*-*-mipseb
ONLY_FOR_PLATFORM+=	*-*-mipsel
ONLY_FOR_PLATFORM+=	*-*-powerpc
ONLY_FOR_PLATFORM+=	*-*-x86_64

# pkg/47587: lua not linked to pthread causes issues with modules
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/bsd.prefs.mk"

# Upstream doesn't support building shared libs on SunOS
# http://www.freelists.org/post/luajit/LuaJIT-on-solaris-64
PLIST_VARS+=		shared
.if ${OPSYS} != "SunOS"
PLIST.shared=		yes
.endif
PRINT_PLIST_AWK+=	{if ($$0 ~ /\.so/) {$$0 = "$${PLIST.shared}" $$0;}}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
