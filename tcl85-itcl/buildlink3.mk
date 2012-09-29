# $NetBSD: buildlink3.mk,v 1.1 2012/09/29 02:11:01 othyro Exp $

BUILDLINK_TREE+=	tcl85-itcl

.if !defined(TCL85_ITCL_BUILDLINK3_MK)
TCL85_ITCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl85-itcl+=	tcl85-itcl>=3.4.1
BUILDLINK_PKGSRCDIR.tcl85-itcl?=	../../wip/tcl85-itcl

.include "../../wip/tcl-tclOO/buildlink3.mk"
.include "../../wip/tk85/buildlink3.mk"
.endif	# TCL85_ITCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl85-itcl
