# $NetBSD: buildlink3.mk,v 1.1 2014/08/20 11:37:00 makoto Exp $

BUILDLINK_TREE+=	verilog08

.if !defined(VERILOG08_BUILDLINK3_MK)
VERILOG08_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.verilog08+=	verilog>=0.8.1nb1
BUILDLINK_ABI_DEPENDS.verilog08+=	verilog>=0.8.7nb1
BUILDLINK_PKGSRCDIR.verilog08?=	../../wip/verilog08

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.endif # VERILOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-verilog08
