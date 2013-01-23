# $NetBSD: buildlink3.mk,v 1.2 2013/01/23 23:53:38 thomasklausner Exp $

BUILDLINK_TREE+=	protobuf-c

.if !defined(PROTOBUF_C_BUILDLINK3_MK)
PROTOBUF_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf-c+=	protobuf-c>=0.15
BUILDLINK_PKGSRCDIR.protobuf-c?=	../../wip/protobuf-c

.endif	# PROTOBUF_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf-c
