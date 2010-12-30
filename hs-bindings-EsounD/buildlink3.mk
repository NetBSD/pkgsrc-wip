# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/30 09:30:43 phonohawk Exp $

BUILDLINK_TREE+=	hs-bindings-EsounD

.if !defined(HS_BINDINGS_ESOUND_BUILDLINK3_MK)
HS_BINDINGS_ESOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bindings-EsounD+=	hs-bindings-EsounD>=0.1
BUILDLINK_PKGSRCDIR.hs-bindings-EsounD?=	../../wip/hs-bindings-EsounD

.include "../../audio/esound/buildlink3.mk"
.include "../../wip/hs-bindings-DSL/buildlink3.mk"
.include "../../wip/hs-bindings-audiofile/buildlink3.mk"
.endif	# HS_BINDINGS_ESOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bindings-EsounD
