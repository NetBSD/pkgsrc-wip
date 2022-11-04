# $NetBSD: buildlink3.mk,v 1.9 2014/01/11 14:42:00 adam Exp $

BUILDLINK_TREE+=	tclx

.if !defined(TCLX_BUILDLINK3_MK)
TCLX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tclx+=	tclx>=tclx-8.4.4
BUILDLINK_ABI_DEPENDS.tclx+=	tclx>=tclx-8.4.4
BUILDLINK_PKGSRCDIR.tclx?=	../../lang/tclx

.include "../../lang/tcl/buildlink3.mk"
.endif # TCLX_BUILDLINK3_MK

BUILDLINK_TREE+=	-tclx
