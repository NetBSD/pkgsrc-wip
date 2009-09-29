# $NetBSD: buildlink3.mk,v 1.2 2009/09/29 21:22:03 pettai Exp $

BUILDLINK_TREE+=	softhsm

.if !defined(SOFTHSM_BUILDLINK3_MK)
SOFTHSM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.softhsm+=	softhsm>=1.0.0rc3nb20090929
BUILDLINK_PKGSRCDIR.softhsm?=	../../wip/softhsm

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.endif	# SOFTHSM_BUILDLINK3_MK

BUILDLINK_TREE+=	-softhsm
