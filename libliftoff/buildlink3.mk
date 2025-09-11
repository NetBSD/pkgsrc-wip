# $NetBSD$

BUILDLINK_TREE+=	libliftoff

.if !defined(LIBLIFTOFF_BUILDLINK3_MK)
LIBLIFTOFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libliftoff+=	libliftoff>=0.5.0
BUILDLINK_ABI_DEPENDS.libliftoff+=	libliftoff>=0.5.0
BUILDLINK_PKGSRCDIR.libliftoff?=	../../wip/libliftoff

.endif # LIBLIFTOFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libliftoff
