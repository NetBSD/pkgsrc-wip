# $NetBSD$

BUILDLINK_TREE+=	tcl-itcl3

.if !defined(TCL_ITCL3_BUILDLINK3_MK)
TCL_ITCL3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-itcl3+=	tcl-itcl3>=3.4.3
BUILDLINK_PKGSRCDIR.tcl-itcl3?=	../../wip/tcl-itcl3

.include "../../lang/tcl/buildlink3.mk"
.endif	# TCL_ITCL3_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-itcl3
