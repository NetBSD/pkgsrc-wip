# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/12 10:41:51 ryo-on Exp $

BUILDLINK_TREE+=	libisofs

.if !defined(LIBISOFS_BUILDLINK3_MK)
LIBISOFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libisofs+=	libisofs>=1.0.4
BUILDLINK_PKGSRCDIR.libisofs?=	../../wip/libisofs

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBISOFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libisofs
