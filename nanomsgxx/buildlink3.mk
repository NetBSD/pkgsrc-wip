# $NetBSD$

BUILDLINK_TREE+=	nanomsgxx

.if !defined(NANOMSGXX_BUILDLINK3_MK)
NANOMSGXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nanomsgxx+=	nanomsgxx>=0.2
BUILDLINK_PKGSRCDIR.nanomsgxx?=		../../wip/nanomsgxx

.include "../../net/nanomsg/buildlink3.mk"
.endif	# NANOMSGXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-nanomsgxx
