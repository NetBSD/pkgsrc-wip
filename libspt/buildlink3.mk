# $NetBSD: buildlink3.mk,v 1.1 2012/08/12 05:48:05 makoto Exp $

BUILDLINK_TREE+=	libspt

.if !defined(LIBSPT_BUILDLINK3_MK)
LIBSPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspt+=	libspt>=1.1
BUILDLINK_PKGSRCDIR.libspt?=	../../wip/libspt
.endif	# LIBSPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspt
