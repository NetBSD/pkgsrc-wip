# $NetBSD$

BUILDLINK_TREE+=	suscan

.if !defined(SUSCAN_BUILDLINK3_MK)
SUSCAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.suscan+=	suscan>=0.1.0
BUILDLINK_PKGSRCDIR.suscan?=	../../wip/suscan

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../wip/sigutils/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# SUSCAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-suscan
