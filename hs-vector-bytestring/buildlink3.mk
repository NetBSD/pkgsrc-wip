# $NetBSD: buildlink3.mk,v 1.3 2014/05/25 21:59:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector-bytestring

.if !defined(HS_VECTOR_BYTESTRING_BUILDLINK3_MK)
HS_VECTOR_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-bytestring+=	hs-vector-bytestring>=0.0.0
BUILDLINK_PKGSRCDIR.hs-vector-bytestring?=	../../wip/hs-vector-bytestring

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-bytestring
