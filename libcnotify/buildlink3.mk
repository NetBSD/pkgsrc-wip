# $NetBSD: buildlink3.mk,v 1.1 2013/05/29 10:29:25 othyro Exp $

BUILDLINK_TREE+=	libcnotify

.if !defined(LIBCNOTIFY_BUILDLINK3_MK)
LIBCNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcnotify+=	libcnotify>=20121224
BUILDLINK_PKGSRCDIR.libcnotify?=	../../wip/libcnotify

.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcnotify
