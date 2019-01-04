# $NetBSD$

BUILDLINK_TREE+=	pike8.0

.if !defined(PIKE8.0_BUILDLINK3_MK)
PIKE8.0_BUILDLINK3_MK:=

BUILDLINK_INCDIRS.pike8.0+=	include/pike8.0

BUILDLINK_API_DEPENDS.pike8.0+=	pike8.0>=8.0.498
BUILDLINK_PKGSRCDIR.pike8.0?=	../../wip/pike8.0

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.endif	# PIKE8.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-pike8.0
