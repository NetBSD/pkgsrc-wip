# $NetBSD: Makefile,v 1.1.1.1 2009/09/30 19:53:43 fhajny Exp $
#

PKGNAME=		lua-sec-0.3.3
DISTNAME=		${PKGNAME:S/-//}
CATEGORIES=		security
MASTER_SITES=		http://luaforge.net/frs/download.php/4160/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.inf.puc-rio.br/~brunoos/luasec/
COMMENT=		Lua binding for OpenSSL library
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=       	lua-socket>=2.0:../../wip/luasocket

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		solaris
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/ssl.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/ssl.lua
	${INSTALL_LIB} ${DESTDIR}${WRKSRC}/src/ssl.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/ssl.so

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
