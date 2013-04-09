# $NetBSD: buildlink3.mk,v 1.1 2013/04/09 07:48:05 jgoamakf Exp $

BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.99beta18
BUILDLINK_PKGSRCDIR.libcaca?=	../../wip/libcaca
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
