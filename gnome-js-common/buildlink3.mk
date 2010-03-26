# $NetBSD: buildlink3.mk,v 1.1 2010/03/26 11:51:30 jihbed Exp $

BUILDLINK_TREE+=	gnome-js-common

.if !defined(GNOME_JS_COMMON_BUILDLINK3_MK)
GNOME_JS_COMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-js-common+=	gnome-js-common>=0.1.1
BUILDLINK_PKGSRCDIR.gnome-js-common?=	../../wip/gnome-js-common
.endif	# GNOME_JS_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-js-common
