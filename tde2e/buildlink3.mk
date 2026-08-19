# $NetBSD$

BUILDLINK_TREE+=	tde2e

.if !defined(TDE2E_BUILDLINK3_MK)
TDE2E_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tde2e+=	tde2e>=1.8.0
BUILDLINK_PKGSRCDIR.tde2e?=	../../wip/tde2e

.include "../../devel/abseil/buildlink3.mk"
.endif	# TDE2E_BUILDLINK3_MK

BUILDLINK_TREE+=	-tde2e
