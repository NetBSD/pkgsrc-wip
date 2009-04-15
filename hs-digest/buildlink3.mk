# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/15 21:00:23 zecrazytux Exp $

BUILDLINK_TREE+=	hs-digest

.if !defined(HS_DIGEST_BUILDLINK3_MK)
HS_DIGEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-digest+=	hs-digest>=0.0.0.5
BUILDLINK_PKGSRCDIR.hs-digest?=	../../wip/hs-digest
.endif	# HS_DIGEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-digest
