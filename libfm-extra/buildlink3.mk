# $NetBSD: buildlink3.mk,v 1.5 2015/04/11 18:01:27 krytarowski Exp $

BUILDLINK_TREE+=	libfm-extra

.if !defined(LIBFM_EXTRA_BUILDLINK3_MK)
LIBFM_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm-extra+=	libfm-extra>=1.2.4
BUILDLINK_PKGSRCDIR.libfm-extra?=	../../wip/libfm-extra

.endif	# LIBFM-EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm-extra
