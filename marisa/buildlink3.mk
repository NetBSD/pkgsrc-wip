# $NetBSD: buildlink3.mk,v 1.1 2013/11/04 00:45:48 ishit Exp $

BUILDLINK_TREE+=	marisa

.if !defined(MARISA_BUILDLINK3_MK)
MARISA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marisa+=	marisa>=0.2.4
BUILDLINK_PKGSRCDIR.marisa?=	../../wip/marisa
.endif	# MARISA_BUILDLINK3_MK

BUILDLINK_TREE+=	-marisa
