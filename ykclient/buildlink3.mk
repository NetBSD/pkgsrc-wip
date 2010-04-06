# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/06 06:00:13 marttikuparinen Exp $

BUILDLINK_TREE+=	ykclient

.if !defined(YKCLIENT_BUILDLINK3_MK)
YKCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykclient+=	ykclient>=2.3
BUILDLINK_PKGSRCDIR.ykclient?=	../../wip/ykclient

.include "../../www/curl/buildlink3.mk"
.endif	# YKCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykclient
