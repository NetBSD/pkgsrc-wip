# $NetBSD$

BUILDLINK_TREE+=	toxcore

.if !defined(TOXCORE_BUILDLINK3_MK)
TOXCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.toxcore+=	toxcore>=0.1.11
BUILDLINK_PKGSRCDIR.toxcore?=	../../wip/toxcore

.include "../../security/libsodium/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.endif	# TOXCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-toxcore
