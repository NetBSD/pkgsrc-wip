# $NetBSD$

BUILDLINK_TREE+=	libglvnd

.if !defined(LIBGLVND_BUILDLINK3_MK)
LIBGLVND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglvnd+=	libglvnd>=1.7.0
BUILDLINK_PKGSRCDIR.libglvnd?=		../../wip/libglvnd

.endif	# LIBGLVND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglvnd
