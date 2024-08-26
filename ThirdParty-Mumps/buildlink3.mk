# $NetBSD$

BUILDLINK_TREE+=	ThirdParty-Mumps

.if !defined(THIRDPARTY_MUMPS_BUILDLINK3_MK)
THIRDPARTY_MUMPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ThirdParty-Mumps+=	ThirdParty-Mumps>=3.0.7
BUILDLINK_PKGSRCDIR.ThirdParty-Mumps?=		../../wip/ThirdParty-Mumps

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif	# THIRDPARTY_MUMPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ThirdParty-Mumps
