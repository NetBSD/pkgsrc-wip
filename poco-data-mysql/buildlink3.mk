# $NetBSD: buildlink3.mk,v 1.2 2009/11/05 05:08:41 schnoebe Exp $

BUILDLINK_TREE+=	poco-data-mysql

.if !defined(POCO_DATA_MYSQL_BUILDLINK3_MK)
POCO_DATA_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-mysql+=	poco-data-mysql>=1.3.5
BUILDLINK_PKGSRCDIR.poco-data-mysql?=	../../wip/poco-data-mysql

.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../wip/poco-data/buildlink3.mk"
.endif # POCO_DATA_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-mysql
