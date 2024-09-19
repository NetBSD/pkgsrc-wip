# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/07 00:53:34 jihbed Exp $

BUILDLINK_TREE+=	libitl

.if !defined(LIBITL_BUILDLINK3_MK)
LIBITL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libitl+=	libitl>=0.6.4
BUILDLINK_PKGSRCDIR.libitl?=	../../wip/libitl
.endif	# LIBITL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libitl
