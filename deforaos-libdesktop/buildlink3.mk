# $NetBSD: buildlink3.mk,v 1.8 2013/11/06 01:22:23 khorben Exp $
#

BUILDLINK_TREE+=	deforaos-libdesktop

.if !defined(DEFORAOS_LIBDESKTOP_BUILDLINK3_MK)
DEFORAOS_LIBDESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdesktop+=	deforaos-libdesktop>=0.0.10
BUILDLINK_PKGSRCDIR.deforaos-libdesktop?=	../../wip/deforaos-libdesktop

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# DEFORAOS_LIBDESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdesktop
