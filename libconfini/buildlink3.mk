# $NetBSD$

BUILDLINK_TREE+=	libconfini

.if !defined(LIBCONFINI_BUILDLINK3_MK)
LIBCONFINI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libconfini+=	libconfini>=1.16.3
BUILDLINK_PKGSRCDIR.libconfini?=	../../wip/libconfini
.endif	# LIBCONFINI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libconfini
