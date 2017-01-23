# $NetBSD$

BUILDLINK_TREE+=	libpatterns

.if !defined(libpatterns_BUILDLINK3_MK)
libpatterns_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpatterns+=	libpatterns>=0.1.0
BUILDLINK_PKGSRCDIR.libpatterns?=	../../wip/libpatterns

.endif # libpatterns_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpatterns
