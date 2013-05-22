# $NetBSD: buildlink3.mk,v 1.1 2013/05/22 18:46:21 szptvlfn Exp $

BUILDLINK_TREE+=	hs-profunctors

.if !defined(HS_PROFUNCTORS_BUILDLINK3_MK)
HS_PROFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-profunctors+=	hs-profunctors>=3.3.0.1
BUILDLINK_PKGSRCDIR.hs-profunctors?=	../../wip/hs-profunctors

.endif	# HS_PROFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-profunctors
