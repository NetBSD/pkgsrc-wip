# $NetBSD$
BUILDLINK_TREE+=	coin-or-lemon

.if !defined(COIN_OR_LEMON_BUILDLINK3_MK)
COIN_OR_LEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coin-or-lemon+=	coin-or-lemon>=1.3.1
BUILDLINK_PKGSRCDIR.coin-or-lemon?=	../../wip/coin-or-lemon

.include "../../math/coinmp/buildlink3.mk"
.endif	# COIN_OR_LEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-coin-or-lemon
