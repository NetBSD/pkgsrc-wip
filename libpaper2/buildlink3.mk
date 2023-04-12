# $NetBSD$

BUILDLINK_TREE+=	libpaper

.if !defined(LIBPAPER_BUILDLINK3_MK)
LIBPAPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpaper+=	libpaper>=2.0.10
BUILDLINK_PKGSRCDIR.libpaper?=		../../wip/libpaper2

.endif	# LIBPAPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpaper
