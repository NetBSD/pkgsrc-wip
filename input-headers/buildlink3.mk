# $NetBSD$

BUILDLINK_TREE+=	input-headers

.if !defined(INPUT_HEADERS_BUILDLINK3_MK)
INPUT_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.input-headers+=	input-headers>=1.26.2
BUILDLINK_ABI_DEPENDS.input-headers+=	input-headers>=1.26.2
BUILDLINK_PKGSRCDIR.input-headers?=	../../wip/input-headers

.endif # INPUT_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-input-headers
