# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 06:05:51 phonohawk Exp $

BUILDLINK_TREE+=	hs-vector-bytestring

.if !defined(HS_VECTOR_BYTESTRING_BUILDLINK3_MK)
HS_VECTOR_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-bytestring+=	hs-vector-bytestring>=0.0.0
BUILDLINK_PKGSRCDIR.hs-vector-bytestring?=	../../wip/hs-vector-bytestring

.include "../../wip/hs-primitive/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-bytestring
