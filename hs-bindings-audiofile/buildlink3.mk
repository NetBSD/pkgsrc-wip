# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/30 09:21:21 phonohawk Exp $

BUILDLINK_TREE+=	hs-bindings-audiofile

.if !defined(HS_BINDINGS_AUDIOFILE_BUILDLINK3_MK)
HS_BINDINGS_AUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bindings-audiofile+=	hs-bindings-audiofile>=0.1
BUILDLINK_PKGSRCDIR.hs-bindings-audiofile?=	../../wip/hs-bindings-audiofile

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../wip/hs-bindings-DSL/buildlink3.mk"
.endif	# HS_BINDINGS_AUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bindings-audiofile
