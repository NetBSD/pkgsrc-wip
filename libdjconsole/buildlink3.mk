# $NetBSD: buildlink3.mk,v 1.1 2012/09/28 03:55:45 othyro Exp $

BUILDLINK_TREE+=	libdjconsole

.if !defined(LIBDJCONSOLE_BUILDLINK3_MK)
LIBDJCONSOLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdjconsole+=	libdjconsole>=0.1.3nb1
BUILDLINK_PKGSRCDIR.libdjconsole?=	../../wip/libdjconsole

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBDJCONSOLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdjconsole
