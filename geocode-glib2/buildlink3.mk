# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:29 wiz Exp $

BUILDLINK_TREE+=	geocode-glib2

.if !defined(GEOCODE_GLIB2_BUILDLINK3_MK)
GEOCODE_GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.geocode-glib2+=	geocode-glib2>=3.26.4
BUILDLINK_ABI_DEPENDS.geocode-glib2?=	geocode-glib2>=3.26.4
BUILDLINK_PKGSRCDIR.geocode-glib2?=	../../wip/geocode-glib2

.include "../../devel/glib2/buildlink3.mk"
.endif	# GEOCODE_GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-geocode-glib2
