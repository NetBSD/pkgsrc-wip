# $NetBSD: buildlink3.mk,v 1.1 2012/01/15 21:46:25 bharder Exp $

BUILDLINK_TREE+=	tcl-expect

.if !defined(TCL_EXPECT_BUILDLINK3_MK)
TCL_EXPECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb1
BUILDLINK_ABI_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb2
BUILDLINK_PKGSRCDIR.tcl-expect?=	../../wip/tcl-expect

.include "../../wip/tcl85/buildlink3.mk"
.endif # TCL_EXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-expect
