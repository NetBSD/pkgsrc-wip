# $NetBSD: buildlink3.mk,v 1.2 2015/03/21 10:16:11 jonthn Exp $

BUILDLINK_TREE+=	msgpack

.if !defined(MSGPACK_BUILDLINK3_MK)
MSGPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.msgpack+=	msgpack>=1.0.0
BUILDLINK_PKGSRCDIR.msgpack?=	../../wip/msgpack-git
.endif	# MSGPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-msgpack
