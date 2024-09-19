# $NetBSD: buildlink3.mk,v 1.5 2009/05/06 10:11:36 cheusov Exp $

BUILDLINK_TREE+=	libwbxml2

.if !defined(LIBWBXML2_BUILDLINK3_MK)
LIBWBXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwbxml2+=	libwbxml2>=0.9.0
BUILDLINK_PKGSRCDIR.libwbxml2?=		../../wip/libwbxml2-patched

.endif # LIBWBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwbxml2
