# $NetBSD$

DISTNAME=	opendbx-1.4.6
CATEGORIES=	devel
MASTER_SITES=	https://linuxnetworks.de/opendbx/download/

MAINTAINER=	jhonas.wernery@mnxsolutions.com
HOMEPAGE=	https://linuxnetworks.de/opendbx/download/
COMMENT=	Extremely lightweight but extensible database access library
LICENSE=	gnu-lgpl-v2

INSTALLATION_DIRS=	bin include lib share

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--with-backends="mysql pgsql sqlite3"
FORCE_CXX_STD=		c++14

PKGCONFIG_OVERRIDE+=	opendbx.pc.in
PKGCONFIG_OVERRIDE+=	opendbxplus.pc.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
