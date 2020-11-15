# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:26 wiz Exp $

BUILDLINK_TREE+=	bitlbee-purple

.if !defined(BITLBEE_BUILDLINK3_MK)
BITLBEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bitlbee-purple+=	bitlbee-purple>=3.6nb1
BUILDLINK_ABI_DEPENDS.bitlbee-purple?=	bitlbee-purple>=3.6nb4
BUILDLINK_PKGSRCDIR.bitlbee-purple?=	../../wip/bitlbee-purple

.include "../../devel/glib2/buildlink3.mk"
.endif	# BITLBEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-bitlbee-purple
