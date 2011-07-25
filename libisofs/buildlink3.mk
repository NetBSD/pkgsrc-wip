# $NetBSD: buildlink3.mk,v 1.3 2011/07/25 13:50:56 ryo-on Exp $

BUILDLINK_TREE+=	libisofs

.if !defined(LIBISOFS_BUILDLINK3_MK)
LIBISOFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libisofs+=	libisofs>=1.1.2
BUILDLINK_PKGSRCDIR.libisofs?=	../../wip/libisofs

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBISOFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libisofs
