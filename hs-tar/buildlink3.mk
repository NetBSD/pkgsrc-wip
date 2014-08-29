# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tar

.if !defined(HS_TAR_BUILDLINK3_MK)
HS_TAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar+=	hs-tar>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-tar+=	hs-tar>=0.4.0.1
BUILDLINK_PKGSRCDIR.hs-tar?=	../../wip/hs-tar
.endif	# HS_TAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar
