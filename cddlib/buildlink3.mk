# $NetBSD$

BUILDLINK_TREE+=	cddlib

.if !defined(CDDLIB_BUILDLINK3_MK)
CDDLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cddlib+=	cddlib>=0.94j
BUILDLINK_PKGSRCDIR.cddlib?=	../../wip/cddlib

#.include "../../devel/gmp/buildlink3.mk"
.endif	# CDDLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cddlib
