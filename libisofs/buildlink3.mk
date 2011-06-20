# $NetBSD: buildlink3.mk,v 1.2 2011/06/20 20:05:13 ryo-on Exp $

BUILDLINK_TREE+=	libisofs

.if !defined(LIBISOFS_BUILDLINK3_MK)
LIBISOFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libisofs+=	libisofs>=1.0.6
BUILDLINK_PKGSRCDIR.libisofs?=	../../wip/libisofs

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBISOFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libisofs
