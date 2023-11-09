# $NetBSD$

BUILDLINK_TREE+=	optional-lite

.if !defined(OPTIONAL_LITE_BUILDLINK3_MK)
OPTIONAL_LITE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.optional-lite?=	build
BUILDLINK_API_DEPENDS.optional-lite+=	optional-lite>=3.5.0
BUILDLINK_PKGSRCDIR.optional-lite?=	../../wip/optional-lite
.endif	# OPTIONAL_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-optional-lite
