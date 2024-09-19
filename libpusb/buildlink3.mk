# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libpusb

.if !defined(LIBPUSB_BUILDLINK3_MK)
LIBPUSB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpusb+=	libpusb>=0.1
BUILDLINK_PKGSRCDIR.libpusb?=	../../wip/libpusb
.endif # LIBPUSB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpusb
