# $NetBSD$

DISTNAME=	v0.1.0
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGNAME=        guile-sqlite3-${DISTNAME:S/v//}
CATEGORIES=	databases
MASTER_SITES=	https://notabug.org/guile-sqlite3/guile-sqlite3/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://notabug.org/guile-sqlite3/guile-sqlite3/
COMMENT=	Guile bindings for the SQLite3 database engine
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/guile-sqlite3
USE_LANGUAGES=	c
USE_TOOLS+=     automake autoconf autoreconf pkg-config
GNU_CONFIGURE=  YES

# not all sqlite3.pc files provide the pkg-config variable, set path manually
# see also patch-configure.ac
CONFIGURE_ARGS+=	SQLITE_LIBDIR=${BUILDLINK_PREFIX.sqlite3}/lib

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

TEST_TARGET=	check

.include "../../lang/guile22/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
