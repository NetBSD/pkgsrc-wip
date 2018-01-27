# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libdssialsacompat

.if !defined(LIBDSSIALSACOMPAT_BUILDLINK3_MK)
LIBDSSIALSACOMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdssialsacompat+=	libdssialsacompat>=1.0.8a
BUILDLINK_PKGSRCDIR.libdssialsacompat?=		../../wip/libdssialsacompat
BUILDLINK_DEPMETHOD.libdssialsacompat?=		build
.endif # LIBDSSIALSACOMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdssialsacompat
