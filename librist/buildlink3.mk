# $NetBSD$

BUILDLINK_TREE+=	librist

.if !defined(LIBRIST_BUILDLINK3_MK)
LIBRIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librist+=	librist>=0.2.18
BUILDLINK_ABI_DEPENDS.librist+=	librist>=0.2.18
BUILDLINK_PKGSRCDIR.librist?=	../../wip/librist

.endif # LIBRIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-librist
