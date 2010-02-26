# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/26 10:04:59 phonohawk Exp $

BUILDLINK_TREE+=	hs-chunks

.if !defined(HS_CHUNKS_BUILDLINK3_MK)
HS_CHUNKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-chunks+=	hs-chunks>=2007.4.18
BUILDLINK_PKGSRCDIR.hs-chunks?=	../../wip/hs-chunks

.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_CHUNKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-chunks
