# $NetBSD$

DISTNAME=	qtbase-everywhere-src-${QTVERSION}
PKGNAME=	qt6-odbc-${QTVERSION}
COMMENT=	Qt6 odbc SQL driver
CATEGORIES=	databases

CONFIGURE_ARGS+=	-sql-odbc
CONFIGURE_ARGS+=	-no-sql-db2
CONFIGURE_ARGS+=	-no-sql-ibase
CONFIGURE_ARGS+=	-no-sql-mysql
CONFIGURE_ARGS+=	-no-sql-oci
CONFIGURE_ARGS+=	-no-sql-psql
CONFIGURE_ARGS+=	-no-sql-sqlite

QTCONFDIR=		src/plugins/sqldrivers

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
