# $NetBSD: buildlink3.mk,v 1.2 2015/08/11 09:55:04 yhardy Exp $

BUILDLINK_TREE+=	libilbc

.if !defined(LIBILBC_BUILDLINK3_MK)
LIBILBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libilbc+=	libilbc>=2.0.2
BUILDLINK_PKGSRCDIR.libilbc?=	../../wip/libilbc
.endif	# LIBILBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libilbc
