# $NetBSD: buildlink3.mk,v 1.2 2026/09/22 07:55:31 ryoon Exp $

BUILDLINK_TREE+=	box2d

.if !defined(BOX2D_BUILDLINK3_MK)
BOX2D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.box2d+=	box2d>=3.1.1
BUILDLINK_PKGSRCDIR.box2d?=	../../graphics/box2d
.endif	# BOX2D_BUILDLINK3_MK

BUILDLINK_TREE+=	-box2d
