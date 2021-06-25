# $NetBSD$

BUILDLINK_TREE+=	sigutils

.if !defined(SIGUTILS_BUILDLINK3_MK)
SIGUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sigutils+=	sigutils>=0.1.0
BUILDLINK_PKGSRCDIR.sigutils?=		../../wip/sigutils

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.endif	# SIGUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sigutils
