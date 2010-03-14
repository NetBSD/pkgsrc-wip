# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/14 09:36:04 helgoman Exp $

BUILDLINK_TREE+=	rope

.if !defined(ROPE_BUILDLINK3_MK)
ROPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rope+=	rope>=0.9.2
BUILDLINK_PKGSRCDIR.rope?=	../../wip/rope
.endif	# ROPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-rope
