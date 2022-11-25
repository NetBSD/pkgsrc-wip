# $NetBSD$
#

BUILDLINK_TREE+=	m4ri

.if !defined(M4RI_BUILDLINK3_MK)
M4RI_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.m4ri?=	build

BUILDLINK_API_DEPENDS.m4ri+=	m4ri>=20200125
BUILDLINK_PKGSRCDIR.m4ri?=	../../wip/m4ri

.include "../../parallel/openmp/buildlink3.mk"
.endif	# M4RI_BUILDLINK3_MK

BUILDLINK_TREE+=	-m4ri
