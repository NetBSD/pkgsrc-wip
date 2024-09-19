# $NetBSD$

BUILDLINK_TREE+=	tcl-iwidgets

.if !defined(TCL_IWIDGETS_BUILDLINK3_MK)
TCL_IWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-iwidgets+=	tcl-iwidgets>=4.0.1
BUILDLINK_PKGSRCDIR.tcl-iwidgets?=	../../wip/tcl-iwidgets
.endif	# TCL_IWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-iwidgets
