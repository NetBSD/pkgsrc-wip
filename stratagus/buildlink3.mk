# $NetBSD$

BUILDLINK_TREE+=	stratagus

.if !defined(STRATAGUS_BUILDLINK3_MK)
STRATAGUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stratagus+=	stratagus-2.4.*
BUILDLINK_PKGSRCDIR.stratagus?=		../../wip/stratagus

.endif # STRATAGUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-stratagus
