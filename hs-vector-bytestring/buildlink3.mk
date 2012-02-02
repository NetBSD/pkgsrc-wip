# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/02 13:11:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-vector-bytestring

.if !defined(HS_VECTOR_BYTESTRING_BUILDLINK3_MK)
HS_VECTOR_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-bytestring+=	hs-vector-bytestring>=0.0.0
BUILDLINK_PKGSRCDIR.hs-vector-bytestring?=	../../wip/hs-vector-bytestring

.include "../../wip/hs-deepseq/buildlink3.mk"
.include "../../wip/hs-primitive/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-bytestring
