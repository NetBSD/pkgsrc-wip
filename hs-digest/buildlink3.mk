# $NetBSD: buildlink3.mk,v 1.2 2013/03/05 22:48:06 szptvlfn Exp $

BUILDLINK_TREE+=	hs-digest

.if !defined(HS_DIGEST_BUILDLINK3_MK)
HS_DIGEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-digest+=	hs-digest>=0.0.1
BUILDLINK_PKGSRCDIR.hs-digest?=	../../wip/hs-digest
.endif	# HS_DIGEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-digest
