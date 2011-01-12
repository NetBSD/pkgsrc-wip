# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/12 01:28:44 phonohawk Exp $

BUILDLINK_TREE+=	hs-tar

.if !defined(HS_TAR_BUILDLINK3_MK)
HS_TAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar+=	hs-tar>=0.3
BUILDLINK_PKGSRCDIR.hs-tar?=	../../wip/hs-text
.endif	# HS_TAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar
