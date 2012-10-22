# $NetBSD: buildlink3.mk,v 1.3 2012/10/22 21:34:57 othyro Exp $

BUILDLINK_TREE+=	tcl85-itcl

.if !defined(TCL85_ITCL_BUILDLINK3_MK)
TCL85_ITCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl85-itcl+=	tcl85-itcl>=3.4.1
BUILDLINK_PKGSRCDIR.tcl85-itcl?=	../../wip/tcl85-itcl

.include "../../x11/tk/buildlink3.mk"
.endif	# TCL85_ITCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl85-itcl
