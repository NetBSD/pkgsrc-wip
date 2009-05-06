# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:18:36 cheusov Exp $

BUILDLINK_TREE+=	xbsql

.if !defined(XBSQL_BUILDLINK3_MK)
XBSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xbsql+=	xbsql>=0.11
BUILDLINK_PKGSRCDIR.xbsql?=	../../wip/xbsql

.include "../../wip/xbase/buildlink3.mk"
.endif # XBSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xbsql
