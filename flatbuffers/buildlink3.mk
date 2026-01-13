# $NetBSD$

BUILDLINK_TREE+=	flatbuffers

.if !defined(FLATBUFFERS_BUILDLINK3_MK)
FLATBUFFERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flatbuffers+=	flatbuffers>=25.12.19
BUILDLINK_PKGSRCDIR.flatbuffers?=	../../wip/flatbuffers
.endif	# FLATBUFFERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flatbuffers
