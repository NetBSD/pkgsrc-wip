# $NetBSD$

BUILDLINK_TREE+=	cgnslib

.if !defined(CGNSLIB_BUILDLINK3_MK)
CGNSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgnslib+=	cgnslib>=2
BUILDLINK_PKGSRCDIR.cgnslib?=	../../wip/cgnslib

.include "../../devel/hdf5/buildlink3.mk"
.endif	# CGNSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgnslib
