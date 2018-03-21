# $NetBSD: buildlink3.mk,v 1.46 2015/10/25 11:05:48 wiz Exp $

BUILDLINK_TREE+=	vlc

.if !defined(VLC_BUILDLINK3_MK)
VLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vlc+=	vlc>=3.0.1
BUILDLINK_PKGSRCDIR.vlc?=	../../multimedia/vlc

.endif	# VLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-vlc
