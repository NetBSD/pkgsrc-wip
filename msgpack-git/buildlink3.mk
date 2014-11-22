# $NetBSD: buildlink3.mk,v 1.1 2014/11/22 22:43:43 jonthn Exp $

BUILDLINK_TREE+=	msgpack

.if !defined(MSGPACK_BUILDLINK3_MK)
MSGPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.msgpack+=	msgpack>=0.5.9nb20141116
BUILDLINK_PKGSRCDIR.msgpack?=	../../wip/msgpack-git
.endif	# MSGPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-msgpack
