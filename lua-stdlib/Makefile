# $NetBSD: Makefile,v 1.2 2008/12/27 20:29:08 cheusov Exp $
#

DISTNAME=	stdlib-8
PKGNAME=	${DISTNAME:S/stdlib/lua-stdlib/}
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/3740/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://luaforge.net/projects/stdlib/
COMMENT=	Standard library for Lua programming language

DEPENDS+=		lua>=5.0:../../lang/lua
DEPENDS+=		lua-lrexlib-pcre:../../wip/lua-lrexlib-pcre

PKG_DESTDIR_SUPPORT=	user-destdir

#DIST_SUBDIR=		lua

WRKSRC=			${WRKDIR}/stdlib

NO_BUILD=		yes
NO_CONFIGURE=		yes

# hack! I don't how to get Lua's directory for modules properly
LUA_VER=		5.1
MODULES_DIR=		lib/lua/${LUA_VER}

INSTALLATION_DIRS+=	${MODULES_DIR}
PLIST_SUBST+=		MODULES_DIR=${MODULES_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${MODULES_DIR}

.include "../../mk/bsd.pkg.mk"
