# $NetBSD: buildlink3.mk,v 1.1 2009/09/29 20:44:23 pettai Exp $

BUILDLINK_TREE+=	softhsm-1.0.0

.if !defined(SOFTHSM_1.0.0_BUILDLINK3_MK)
SOFTHSM_1.0.0_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.softhsm-1.0.0+=	softhsm-1.0.0>=RC3nb20090926
BUILDLINK_PKGSRCDIR.softhsm-1.0.0?=	../../wip/softhsm

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/botan/buildlink3.mk"
.endif	# SOFTHSM_1.0.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-softhsm-1.0.0
