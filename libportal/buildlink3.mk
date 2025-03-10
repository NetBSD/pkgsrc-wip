# $NetBSD$

BUILDLINK_TREE+=	libportal

.if !defined(LIBPORTAL_BUILDLINK3_MK)
LIBPORTAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libportal+=	libportal>=0.9.1
BUILDLINK_PKGSRCDIR.libportal?=		../../wip/libportal

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBPORTAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libportal
