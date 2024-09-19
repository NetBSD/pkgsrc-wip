# $NetBSD$

BUILDLINK_TREE+=	libplist2

.if !defined(LIBPLIST2_BUILDLINK3_MK)
LIBPLIST2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist2+=	libplist2>=2.2.0
BUILDLINK_ABI_DEPENDS.libplist2+=	libplist2>=2.2.0
BUILDLINK_PKGSRCDIR.libplist2?=		../../wip/libplist2

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBPLIST2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist2
