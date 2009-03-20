# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libwbxml2

BUILDLINK_API_DEPENDS.libwbxml2+=	libwbxml2>=0.9.0
BUILDLINK_PKGSRCDIR.libwbxml2?=		../../wip/libwbxml2-patched
.endif	# LIBWBXML2_BUILDLINK_MK
.endif # LIBWBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwbxml2
