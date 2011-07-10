# $NetBSD: buildlink3.mk,v 1.8 2011/07/10 16:23:31 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-mixer

.if !defined(XFCE4_MIXER_BUILDLINK3_MK)
XFCE4_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mixer+=	xfce4-mixer>=4.8.0
BUILDLINK_PKGSRCDIR.xfce4-mixer?=	../../wip/xfce4-mixer

.endif # XFCE4_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mixer
