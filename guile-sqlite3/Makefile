# $NetBSD$

DISTNAME=	v0.1.0
PKGNAME=        guile-sqlite3
CATEGORIES=	databases
MASTER_SITES=	https://notabug.org/guile-sqlite3/guile-sqlite3/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://notabug.org/guile-sqlite3/guile-sqlite3/
COMMENT=	Guile bindings for the SQLite3 database engine
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/guile-sqlite3
USE_LANGUAGES=	guile c
# USE_LIBTOOL=    YES

CONFIGURE_ARGS+= --prefix=${PREFIX}
GNU_CONFIGURE=  YES
USE_TOOLS+=     automake autoconf autoreconf pkg-config

# CONFIGURE_ENV+= SQLITE_LIBS="${PREFIX}/lib"
# CONFIGURE_ENV+= SQLITE_LIBS=${BUILDLINK_PREFIX.sqlite3}
#CONFIGURE_ARGS+=   --with-sqlite-incdir=${BUILDLINK_PREFIX.sqlite}/include
#CONFIGURE_ARGS+=   --with-sqlite-libdir=${BUILDLINK_PREFIX.sqlite}/lib
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${LOCALBASE}/guile/2.2/share/aclocal -vif

DEPENDS+= guile>=2.2:../../lang/guile22
DEPENDS+= sqlite3:../../databases/sqlite3

.include "../../lang/guile22/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
