# $NetBSD: $

BUILDLINK_TREE+=	lightdm

.if !defined(LIGHTDM_BUILDLINK3_MK)
LIGHTDM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lightdm+=	lightdm>=1.30.0
BUILDLINK_PKGSRCDIR.lightdm?=	../../wip/lightdm # s,local,x11,

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# LIGHTDM_BUILDLINK3_MK

BUILDLINK_TREE+=	-lightdm
