# $NetBSD$
# XXX	BUILDLINK_DEPMETHOD.multichoose?=	build

BUILDLINK_TREE+=	multichoose

.if !defined(MULTICHOOSE_BUILDLINK3_MK)
MULTICHOOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.multichoose+=	multichoose>=d60d639af93f8720e019d824bb2405eb4523fb16
BUILDLINK_PKGSRCDIR.multichoose?=	../../wip/multichoose
.endif	# MULTICHOOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-multichoose
