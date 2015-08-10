# $NetBSD: buildlink3.mk,v 1.1 2015/08/10 22:33:01 yhardy Exp $

BUILDLINK_TREE+=	libilbc

.if !defined(LIBILBC_BUILDLINK3_MK)
LIBILBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libilbc+=	libilbc>=2.0.2
BUILDLINK_PKGSRCDIR.libilbc?=	../../local/libilbc
.endif	# LIBILBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libilbc
