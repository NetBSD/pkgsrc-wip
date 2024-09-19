# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-chunks

.if !defined(HS_CHUNKS_BUILDLINK3_MK)
HS_CHUNKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-chunks+=	hs-chunks>=2007.4.18
BUILDLINK_ABI_DEPENDS.hs-chunks+=	hs-chunks>=2007.4.18
BUILDLINK_PKGSRCDIR.hs-chunks?=		../../wip/hs-chunks

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_CHUNKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-chunks
