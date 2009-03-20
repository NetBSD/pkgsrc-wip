# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	jalview_binary

BUILDLINK_API_DEPENDS.jalview_binary+=	jalview_binary>=1.8
BUILDLINK_PKGSRCDIR.jalview_binary?=	../../wip/jalview
.endif # JALVIEW_BINARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-jalview_binary
