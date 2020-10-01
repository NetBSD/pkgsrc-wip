# $NetBSD$

BUILDLINK_TREE+=	gnome-common

.if !defined(GNOME_COMMON_BUILDLINK3_MK)
GNOME_COMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-common+=	gnome-common>=3.18.0
BUILDLINK_PKGSRCDIR.gnome-common?=	../../wip/gnome-common
.endif	# GNOME_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-common
