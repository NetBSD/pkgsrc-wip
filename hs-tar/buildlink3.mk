# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/01 06:58:51 phonohawk Exp $

BUILDLINK_TREE+=	hs-tar

.if !defined(HS_TAR_BUILDLINK3_MK)
HS_TAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar+=	hs-tar>=0.3.1.0
BUILDLINK_PKGSRCDIR.hs-tar?=	../../wip/hs-tar
.endif	# HS_TAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar
