# $NetBSD: buildlink3.mk,v 1.1 2015/03/01 15:44:34 jonthn Exp $
BUILDLINK_TREE+=	libvterm

.if !defined(LIBVTERM_BUILDLINK3_MK)
LIBVTERM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvterm+=	libvterm>=0.0.0
BUILDLINK_PKGSRCDIR.libvterm?=		../../wip/libvterm
.endif	# LIBVTERM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvterm
