# $NetBSD$

BUILDLINK_TREE+=	libzrtp

.if !defined(LIBZRTP_BUILDLINK3_MK)
LIBZRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzrtp+=	libzrtp>=0.7.1
BUILDLINK_ABI_DEPENDS.libzrtp?=	libzrtp>=0.7.1
BUILDLINK_PKGSRCDIR.libzrtp?=	../../wip/libzrtp
.endif	# LIBZRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzrtp
