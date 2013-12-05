# $NetBSD: buildlink3.mk,v 1.2 2013/12/05 03:10:15 phonohawk Exp $

BUILDLINK_TREE+=	hs-tar

.if !defined(HS_TAR_BUILDLINK3_MK)
HS_TAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar+=	hs-tar>=0.4.0
BUILDLINK_PKGSRCDIR.hs-tar?=	../../wip/hs-tar
.endif	# HS_TAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar
