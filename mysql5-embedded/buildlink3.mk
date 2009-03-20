# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	mysql-embedded

.if !defined(MYSQL_EMBEDDED_BUILDLINK3_MK)
MYSQL_EMBEDDED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-embedded+=	mysql-embedded>=5.0.67
BUILDLINK_PKGSRCDIR.mysql-embedded?=	../../wip/mysql5-embedded

.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # MYSQL_EMBEDDED_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-embedded
