# $NetBSD$

DISTNAME=	LuaJIT-2.0.${TIMESTAMP}
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT2/}
CATEGORIES=	lang lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=LuaJIT/}
GITHUB_PROJECT=	${DISTNAME:C/-[^-]*$//}
GITHUB_TAG=	cae36118
TIMESTAMP=	1710087801	# git show --no-patch --format=%ct

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

USE_TOOLS+=	gmake

pre-configure:
	${ECHO} ${TIMESTAMP} >${WRKSRC}/.relver

# LuaJIT 2.1 supports mips64 and aarch64.
ONLY_FOR_PLATFORM+=	*-*-*arm*
ONLY_FOR_PLATFORM+=	*-*-i386
ONLY_FOR_PLATFORM+=	*-*-mipseb
ONLY_FOR_PLATFORM+=	*-*-mipsel
ONLY_FOR_PLATFORM+=	*-*-powerpc
ONLY_FOR_PLATFORM+=	*-*-x86_64

# Address pkg/47587 lua not linked to pthread causes issues with modules
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
