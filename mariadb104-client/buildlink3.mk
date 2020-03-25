# $NetBSD$

BUILDLINK_TREE+=	mariadb-client

.if !defined(MARIADB_CLIENT_BUILDLINK3_MK)
MARIADB_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-client+=	mariadb-client>=10.4.0
BUILDLINK_ABI_DEPENDS.mariadb-client+=	mariadb-client>=10.4.0
BUILDLINK_PKGSRCDIR.mariadb-client?=	../../wip/mariadb104-client
BUILDLINK_INCDIRS.mariadb-client+=	include/mysql
BUILDLINK_LIBDIRS.mariadb-client+=	lib

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # MARIADB_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-client
