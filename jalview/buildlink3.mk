# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 09:59:39 cheusov Exp $

BUILDLINK_TREE+=	jalview_binary

.if !defined(JALVIEW_BINARY_BUILDLINK3_MK)
JALVIEW_BINARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jalview_binary+=	jalview_binary>=1.8
BUILDLINK_PKGSRCDIR.jalview_binary?=	../../wip/jalview
.endif # JALVIEW_BINARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-jalview_binary
