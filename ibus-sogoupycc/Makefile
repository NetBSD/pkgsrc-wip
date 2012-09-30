# $NetBSD: Makefile,v 1.4 2012/09/30 05:44:14 asau Exp $
#

DISTNAME=	ibus-sogoupycc-0.2.5
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus-sogoupycc.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-sogoupycc/
COMMENT=	Sogou Pinyin cloud client for IBus
LICENSE=	gnu-gpl-v2

DEPENDS+=	lua-socket-[0-9]*:../../wip/luasocket

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

REPLACE_INTERPRETER+=	lua
REPLACE.lua.old=	.*lua
REPLACE.lua.new=	${BUILDLINK_PREFIX.lua}/bin/lua
REPLACE_FILES.lua=	fetcher

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
