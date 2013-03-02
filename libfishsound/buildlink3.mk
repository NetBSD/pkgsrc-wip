# $NetBSD: buildlink3.mk,v 1.1 2013/03/02 15:41:45 othyro Exp $

BUILDLINK_TREE+=	libfishsound

.if !defined(LIBFISHSOUND_BUILDLINK3_MK)
LIBFISHSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfishsound+=	libfishsound>=1.0.0
BUILDLINK_PKGSRCDIR.libfishsound?=	../../wip/libfishsound

.include "../../audio/flac/buildlink3.mk"
.include "../../wip/liboggz/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.endif	# LIBFISHSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfishsound
