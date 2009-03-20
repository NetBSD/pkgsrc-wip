# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xbsql

BUILDLINK_API_DEPENDS.xbsql+=	xbsql>=0.11
BUILDLINK_PKGSRCDIR.xbsql?=	../../wip/xbsql

.include "../../wip/xbase/buildlink3.mk"
.endif # XBSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xbsql
