# $NetBSD$

BUILDLINK_TREE+=	libsfdo

.if !defined(LIBSFDO_BUILDLINK3_MK)
LIBSFDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsfdo+=	libsfdo>=0.1.4
BUILDLINK_ABI_DEPENDS.libsfdo+=	libsfdo>=0.1.4
BUILDLINK_PKGSRCDIR.libsfdo?=	../../wip/libsfdo

.endif # LIBSFDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsfdo
