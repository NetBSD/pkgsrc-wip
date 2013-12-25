# $NetBSD: buildlink3.mk,v 1.9 2013/12/25 19:43:13 khorben Exp $
#

BUILDLINK_TREE+=	deforaos-libdesktop

.if !defined(DEFORAOS_LIBDESKTOP_BUILDLINK3_MK)
DEFORAOS_LIBDESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdesktop+=	deforaos-libdesktop>=0.1.0
BUILDLINK_PKGSRCDIR.deforaos-libdesktop?=	../../wip/deforaos-libdesktop

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# DEFORAOS_LIBDESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdesktop
