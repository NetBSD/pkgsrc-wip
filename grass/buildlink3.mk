# $NetBSD: buildlink3.mk,v 1.6 2009/05/18 16:08:47 brook1 Exp $

BUILDLINK_TREE+=	grass

.if !defined(GRASS_BUILDLINK3_MK)
GRASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grass+=	grass>=6.3.0
BUILDLINK_PKGSRCDIR.grass?=	../../wip/grass

.endif	# GRASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-grass
