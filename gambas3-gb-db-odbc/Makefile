# $NetBSD$

BUILD_DIRS=	gb.db.odbc
GB_DEPENDS=	gambas3-gb-db
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-db-odbc-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	ODBC driver for Gambas

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
