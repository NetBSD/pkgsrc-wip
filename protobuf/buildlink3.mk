# $NetBSD: buildlink3.mk,v 1.2 2013/03/29 09:17:26 asau Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=3.0.0
BUILDLINK_PKGSRCDIR.protobuf?=	../../wip/protobuf

.include "../../devel/zlib/buildlink3.mk"
.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
