# $NetBSD: buildlink3.mk,v 1.1 2012/12/30 01:21:51 othyro Exp $

BUILDLINK_TREE+=	libticables2

.if !defined(LIBTICABLES2_BUILDLINK3_MK)
LIBTICABLES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticables2+=	libticables2>=1.3.3
BUILDLINK_PKGSRCDIR.libticables2?=	../../wip/libticables2

.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTICABLES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticables2
