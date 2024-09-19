# $NetBSD$

BUILDLINK_TREE+=	intervaltree

.if !defined(INTERVALTREE_BUILDLINK3_MK)
INTERVALTREE_BUILDLINK3_MK:=
BUILDLINK_DEPMETHOD.intervaltree?=	build

BUILDLINK_API_DEPENDS.intervaltree+=	intervaltree>=0.0.0.20151213
BUILDLINK_PKGSRCDIR.intervaltree?=	../../wip/intervaltree
.endif	# INTERVALTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-intervaltree
