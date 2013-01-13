# $NetBSD: buildlink3.mk,v 1.1 2013/01/13 00:42:39 wongk Exp $

BUILDLINK_TREE+=	protobuf-c

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf-c+=	protobuf-c>=0.15
BUILDLINK_PKGSRCDIR.protobuf-c?=	../../wip/protobuf-c

.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf-c
