# $NetBSD$

BUILD_DIRS=	gb.db.mysql
GB_DEPENDS=	gambas3-gb-db
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-db-mysql-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	MySQL driver for Gambas

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
