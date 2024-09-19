# $NetBSD: buildlink3.mk,v 1.1 2013/01/13 00:42:39 wongk Exp $

BUILDLINK_TREE+=	polarssl

.if !defined(POLARSSL_BUILDLINK3_MK)
POLARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polarssl+=	polarssl>=1.1.4
BUILDLINK_PKGSRCDIR.polarssl?=		../../wip/polarssl11

.endif	# POLARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-polarssl
