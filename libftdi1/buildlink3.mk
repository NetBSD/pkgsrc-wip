# $NetBSD: buildlink3.mk,v 1.2 2015/01/16 18:09:11 nros Exp $

BUILDLINK_TREE+=	libftdi1

.if !defined(LIBFTDI1_BUILDLINK3_MK)
LIBFTDI1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi1+=	libftdi1>=1.2
BUILDLINK_PKGSRCDIR.libftdi1?=		../../wip/libftdi1

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBFTDI1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi1
