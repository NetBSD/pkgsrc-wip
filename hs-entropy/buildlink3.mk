# $NetBSD: buildlink3.mk,v 1.2 2013/09/08 08:50:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-entropy

.if !defined(HS_ENTROPY_BUILDLINK3_MK)
HS_ENTROPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-entropy+=	hs-entropy>=0.2.2
BUILDLINK_PKGSRCDIR.hs-entropy?=	../../wip/hs-entropy
.endif	# HS_ENTROPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-entropy
