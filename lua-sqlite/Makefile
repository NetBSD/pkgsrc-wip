# $NetBSD: Makefile,v 1.1.1.1 2004/04/05 11:39:01 poppnk Exp $
#

DISTNAME=	lsqlite_src
PKGNAME=	lua-sqlite-20030228
CATEGORIES=	wip databases
MASTER_SITES=	http://lua-users.org/files/wiki_insecure/binary_modules/luasqlite/
EXTRACT_SUFX=	.zip

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lua-users.org/wiki/LuaSqlite
COMMENT=	SQLite binding for LUA

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=		yes

do-build:
	${CC} ${WRKSRC}/lsqlite.c -I${PREFIX}/include -L${PREFIX}/lib \
	-shared -llua -lsqlite -llualib -o ${WRKSRC}/libluasqlite.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlite.so ${PREFIX}/lib/

.include "../../lang/lua/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
