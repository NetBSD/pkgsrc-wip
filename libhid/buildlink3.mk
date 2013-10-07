# $NetBSD: buildlink3.mk,v 1.1 2013/10/07 12:05:46 makoto Exp $

BUILDLINK_TREE+=	libhid

.if !defined(LIBHID_BUILDLINK3_MK)
LIBHID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhid+=	libhid>=0.2
BUILDLINK_PKGSRCDIR.libhid?=	../../wip/libhid
.endif	# LIBHID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhid
