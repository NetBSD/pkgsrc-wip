# $NetBSD: Makefile,v 1.5 2009/08/10 20:02:30 cheusov Exp $
#

.include "../../wip/libdbi/Makefile_drivers"

LICENSE=		gnu-lgpl-v2

DRIVER=			mysql

COMMENT=		MySQL driver for libdbi, a database abstraction

CONFLICTS=		libdbi-mysql-[0-9]*

CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ARGS+=	--with-mysql-incdir=${BUILDLINK_PREFIX.mysql-client}/include
CONFIGURE_ARGS+=	--with-mysql-libdir=${BUILDLINK_PREFIX.mysql-client}/lib

.include "../../wip/libdbi/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
