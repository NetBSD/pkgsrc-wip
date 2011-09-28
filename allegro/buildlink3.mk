# $NetBSD: buildlink3.mk,v 1.4 2011/09/28 14:20:29 ryo-on Exp $

BUILDLINK_TREE+=	allegro

.if !defined(ALLEGRO_BUILDLINK3_MK)
ALLEGRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro+=	allegro>=4.4.2
BUILDLINK_PKGSRCDIR.allegro?=	../../wip/allegro

.endif	# ALLEGRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro
