# $NetBSD: buildlink3.mk,v 1.1 2014/08/10 00:06:55 thomasklausner Exp $

BUILDLINK_TREE+=	librem

.if !defined(LIBREM_BUILDLINK3_MK)
LIBREM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librem+=	librem>=0.4.6
BUILDLINK_PKGSRCDIR.librem?=	../../wip/librem

.endif	# LIBREM_BUILDLINK3_MK

BUILDLINK_TREE+=	-librem
