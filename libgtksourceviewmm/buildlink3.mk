# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libgtksourceviewmm

.if !defined(LIBGTKSOURCEVIEWMM_BUILDLINK3_MK)
LIBGTKSOURCEVIEWMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtksourceviewmm+=	libgtksourceviewmm>=0.3.1
BUILDLINK_ABI_DEPENDS.libgtksourceviewmm?=	libgtksourceviewmm>=0.3.1nb2
BUILDLINK_PKGSRCDIR.libgtksourceviewmm?=	../../wip/libgtksourceviewmm

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # LIBGTKSOURCEVIEWMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtksourceviewmm
