# $NetBSD: buildlink3.mk,v 1.1 2013/12/20 02:19:53 makoto Exp $

BUILDLINK_TREE+=	verilog-current

.if !defined(VERILOG_CURRENT_BUILDLINK3_MK)
VERILOG_CURRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.verilog-current+=	verilog-current>=20021019
BUILDLINK_ABI_DEPENDS.verilog-current+=	verilog-current>=20060809
BUILDLINK_PKGSRCDIR.verilog-current?=	../../cad/verilog-current
.endif # VERILOG_CURRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-verilog-current
