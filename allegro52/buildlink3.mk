# $NetBSD: buildlink3.mk,v 1.12 2016/06/16 06:00:46 wiz Exp $

BUILDLINK_TREE+=	allegro

.if !defined(ALLEGRO_BUILDLINK3_MK)
ALLEGRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro+=	allegro>=5.2.0
BUILDLINK_PKGSRCDIR.allegro?=	../../wip/allegro52

.include "../../x11/libXcursor/buildlink3.mk"
.endif	# ALLEGRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro
