# $NetBSD$

BUILDLINK_TREE+=	libndp

.if !defined(LIBNDP_BUILDLINK3_MK)
LIBNDP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libndp+=	libndp>=1.9
BUILDLINK_PKGSRCDIR.libndp?=	../../wip/libndp
.endif	# LIBNDP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libndp
