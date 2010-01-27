# $NetBSD: buildlink3.mk,v 1.1 2010/01/27 06:55:34 phonohawk Exp $

BUILDLINK_TREE+=	aubio

.if !defined(AUBIO_BUILDLINK3_MK)
AUBIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aubio+=	aubio>=0.3.2
BUILDLINK_PKGSRCDIR.aubio?=	../../wip/aubio

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.endif	# AUBIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-aubio
