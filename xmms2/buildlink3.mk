# $NetBSD: buildlink3.mk,v 1.17 2014/04/18 16:17:13 thomasklausner Exp $

BUILDLINK_TREE+=	xmms2

.if !defined(XMMS2_BUILDLINK3_MK)
XMMS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmms2+=	xmms2>=0.8nb1
BUILDLINK_PKGSRCDIR.xmms2?=	../../wip/xmms2

.endif	# XMMS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmms2
