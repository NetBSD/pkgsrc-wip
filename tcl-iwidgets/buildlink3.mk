# $NetBSD: buildlink3.mk,v 1.1 2012/09/29 02:59:47 othyro Exp $

BUILDLINK_TREE+=	tcl-iwidgets

.if !defined(TCL_IWIDGETS_BUILDLINK3_MK)
TCL_IWIDGETS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.tcl-iwidgets?=	build

BUILDLINK_API_DEPENDS.tcl-iwidgets+=	tcl-iwidgets>=4.0.1
BUILDLINK_PKGSRCDIR.tcl-iwidgets?=	../../wip/tcl-iwidgets

#.include "../../wip/tcl85-itcl/buildlink3.mk"
.endif	# TCL_IWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-iwidgets
