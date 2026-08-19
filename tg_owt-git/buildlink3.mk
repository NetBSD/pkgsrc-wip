# $NetBSD$

BUILDLINK_TREE+=	tg_owt

.if !defined(TG_OWT_BUILDLINK3_MK)
TG_OWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tg_owt+=	tg_owt-git-[0-9]*
BUILDLINK_PKGSRCDIR.tg_owt?=	../../wip/tg_owt-git

.include "../../wip/libyuv-git/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.endif	# TG_OWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tg_owt
