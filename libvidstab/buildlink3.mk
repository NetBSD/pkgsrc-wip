# $NetBSD$

BUILDLINK_TREE+=	libvidstab

.if !defined(LIBVIDSTAB_BUILDLINK3_MK)
LIBVIDSTAB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvidstab+=	libvidstab>=0.98b
BUILDLINK_PKGSRCDIR.libvidstab?=	../../wip/libvidstab
.endif	# LIBVIDSTAB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvidstab
