# $NetBSD: buildlink3.mk,v 1.1 2013/12/05 21:26:34 thomasklausner Exp $

BUILDLINK_TREE+=	libircclient

.if !defined(LIBIRCCLIENT_BUILDLINK3_MK)
LIBIRCCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libircclient+=	libircclient>=1.7
BUILDLINK_PKGSRCDIR.libircclient?=	../../wip/libircclient
.endif	# LIBIRCCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libircclient
