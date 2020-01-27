# $NetBSD: Makefile,v 1.11 2017/09/16 19:53:51 alnsn Exp $
#

DISTNAME=	LuaJIT-2.1.0-beta3
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT21/:S/-beta/beta/}
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

CONFLICTS+=	LuaJIT2-[0-9]*

USE_TOOLS+=	gmake

NOT_PAX_MPROTECT_SAFE+=	bin/luajit-${PKGVERSION}

# Address pkg/47587 lua not linked to pthread causes issues with modules
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${OS_VERSION:R} >= 19
CFLAGS.Darwin+=		-fno-stack-check
MAKE_ARGS+=		XCFLAGS=-DLUAJIT_ENABLE_GC64
.endif


# Upstream doesn't support building shared libs on SunOS
# http://www.freelists.org/post/luajit/LuaJIT-on-solaris-64
PLIST_VARS+=		shared
.if ${OPSYS} != "SunOS"
PLIST.shared=		yes
.endif
PRINT_PLIST_AWK+=	{if ($$0 ~ /\.so/) {$$0 = "$${PLIST.shared}" $$0;}}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
