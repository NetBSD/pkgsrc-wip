# $NetBSD: buildlink3.mk,v 1.2 2010/10/31 15:34:53 mjoellnir Exp $

BUILDLINK_TREE+=	libpar2

.if !defined(LIBPAR2_BUILDLINK3_MK)
LIBPAR2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpar2+=	libpar2>=0.2
BUILDLINK_PKGSRCDIR.libpar2?=	../../wip/libpar2

BUILDLINK_INCDIRS.libpar2+=	include/libpar2

.include "../../devel/libsigc++/buildlink3.mk"
.endif	# LIBPAR2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpar2
