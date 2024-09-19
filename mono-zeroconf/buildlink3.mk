# $NetBSD: buildlink3.mk,v 1.3 2013/06/17 12:45:12 thomasklausner Exp $

BUILDLINK_TREE+=	mono-zeroconf

.if !defined(MONO_ZEROCONF_BUILDLINK3_MK)
MONO_ZEROCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-zeroconf+=	mono-zeroconf>=0.8.0
BUILDLINK_ABI_DEPENDS.mono-zeroconf?=	mono-zeroconf>=0.9.0nb2
BUILDLINK_PKGSRCDIR.mono-zeroconf?=	../../wip/mono-zeroconf


.include "../../lang/mono2/buildlink3.mk"
.endif	# MONO_ZEROCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-zeroconf
