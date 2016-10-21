# $NetBSD$

BUILDLINK_TREE+=	tcl-itcl

.if !defined(TCL_ITCL_BUILDLINK3_MK)
TCL_ITCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-itcl+=	tcl-itcl>=itcl3.4.3
BUILDLINK_PKGSRCDIR.tcl-itcl?=	../../wip/tcl-itcl

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TCL_ITCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-itcl
