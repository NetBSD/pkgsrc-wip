# $NetBSD: Makefile,v 1.4 2010/02/12 12:36:10 fhajny Exp $
#

DISTNAME=		luasec-0.4
PKGNAME=		${DISTNAME:S/lua/lua-/}
CATEGORIES=		security
MASTER_SITES=		http://luaforge.net/frs/download.php/4255/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.inf.puc-rio.br/~brunoos/luasec/
COMMENT=		Lua binding for OpenSSL library
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=       	lua-socket>=2.0:../../wip/luasocket

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		solaris
.else
BUILD_TARGET=		bsd
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/ssl.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/ssl.lua
	${INSTALL_LIB} ${WRKSRC}/src/ssl.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/ssl.so

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
