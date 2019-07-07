# $NetBSD$

BUILDLINK_TREE+=	stormlib

.if !defined(STORMLIB_BUILDLINK3_MK)
STORMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stormlib+=	stormlib-9.*
BUILDLINK_PKGSRCDIR.stormlib?=		../../wip/stormlib

.endif # STORMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-stormlib
