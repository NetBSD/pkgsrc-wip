# $NetBSD: buildlink3.mk,v 1.2 2009/09/26 19:50:53 pettai Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.8.6
BUILDLINK_PKGSRCDIR.botan?=	../../wip/botan
.endif	# BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
