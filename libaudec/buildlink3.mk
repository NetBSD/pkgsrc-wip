# $NetBSD$

BUILDLINK_TREE+=	libaudec

.if !defined(LIBAUDEC_BUILDLINK3_MK)
LIBAUDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudec+=	libaudec>=0.2.4
BUILDLINK_ABI_DEPENDS.libaudec+=	libaudec>=0.2.4
BUILDLINK_PKGSRCDIR.libaudec?=		../../wip/libaudec
.endif # LIBAUDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudec
