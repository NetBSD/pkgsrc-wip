# $NetBSD$
# XXX	BUILDLINK_DEPMETHOD.multichoose?=	build

BUILDLINK_TREE+=	multichoose

.if !defined(MULTICHOOSE_BUILDLINK3_MK)
MULTICHOOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.multichoose+=	multichoose>=0.0.0.20151117
BUILDLINK_PKGSRCDIR.multichoose?=	../../wip/multichoose
.endif	# MULTICHOOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-multichoose
