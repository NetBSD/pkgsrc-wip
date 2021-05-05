# $NetBSD$
BUILDLINK_DEPMETHOD.libxtendc?=	build

BUILDLINK_TREE+=	libxtendc

.if !defined(LIBXTENDC_BUILDLINK3_MK)
LIBXTENDC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtendc+=	libxtendc>=0.0.1.1
BUILDLINK_PKGSRCDIR.libxtendc?=	../../wip/libxtendc
.endif	# LIBXTENDC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtendc
