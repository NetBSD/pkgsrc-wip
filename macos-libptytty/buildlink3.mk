# $NetBSD

BUILDLINK_TREE+=	libptytty

.if !defined(LIBPTYTTY_BUILDLINK3_MK)
LIBPTYTTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libptytty+=	libptytty>=2.0
BUILDLINK_ABI_DEPENDS.libptytty+=	libptytty>=2.0
BUILDLINK_PKGSRCDIR.libptytty?=	../../wip/macos-libptytty

.endif # LIBPTYTTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libptytty
