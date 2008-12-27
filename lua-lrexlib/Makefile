# $NetBSD: Makefile,v 1.1.1.1 2008/12/27 18:09:28 cheusov Exp $
#

DISTNAME=	lrexlib-2.4.0
PKGNAME=	${DISTNAME:S/lrexlib/lua-lrexlib-posix/}
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/3599/
EXTRACT_SUFX=	.zip

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://luaforge.net/projects/lrexlib
COMMENT=	POSIX regexp library for Lua (lrexlib project)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

BUILD_TARGET=		build_posix
TEST_TARGET=		test_posix

MAKE_FILE=		makefile

# hack! I don't how to get it properly
LUA_VER=		5.1
MODULES_DIR=		${PREFIX}/lib/lua/${LUA_VER}

#
PLIST_SUBST+=		LUA_VER=${LUA_VER}

MAKE_FLAGS+=		LIBS=${LIBS:Q}
MAKE_FLAGS+=		LIBTOOL=${LIBTOOL:Q}
MAKE_FLAGS+=		MODULES_DIR=${MODULES_DIR}

INSTALLATION_DIRS+=	${MODULES_DIR}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
	    ${WRKSRC}/src/posix/rex_posix.la ${DESTDIR}${MODULES_DIR}

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
