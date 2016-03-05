# $NetBSD$

BUILDLINK_TREE+=	libgweather

.if !defined(LIBGWEATHER_BUILDLINK3_MK)
LIBGWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=3.16.1
BUILDLINK_PKGSRCDIR.libgweather?=	../../wip/libgweather

.endif	# LIBGWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather
