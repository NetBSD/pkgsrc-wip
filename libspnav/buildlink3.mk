# $NetBSD$

BUILDLINK_TREE+=	libspnav

.if !defined(LIBSPNAV_BUILDLINK3_MK)
LIBSPNAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspnav+=	libspnav>=1.2
BUILDLINK_PKGSRCDIR.libspnav?=		../../wip/libspnav

.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBSPNAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspnav
