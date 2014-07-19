# $NetBSD: buildlink3.mk,v 1.1 2014/07/19 12:51:31 fhajny Exp $

BUILDLINK_TREE+=	liblogging

.if !defined(LIBLOGGING_BUILDLINK3_MK)
LIBLOGGING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblogging+=	liblogging>=1.0.4
BUILDLINK_ABI_DEPENDS.liblogging+=	liblogging>=1.0.4
BUILDLINK_PKGSRCDIR.liblogging?=	../../wip/liblogging

.endif # LIBLOGGING_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblogging
