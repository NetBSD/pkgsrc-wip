# $NetBSD$

BUILDLINK_TREE+=	simplesocket

.if !defined(SIMPLESOCKET_BUILDLINK3_MK)
SIMPLESOCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simplesocket+=	simplesocket>=0.0.0.20240102
BUILDLINK_PKGSRCDIR.simplesocket?=	../../wip/simplesocket

.include "../../textproc/fmtlib/buildlink3.mk"
.endif	# SIMPLESOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-simplesocket
