# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/27 09:30:42 xtraeme Exp $
#
# This Makefile fragment is included by packages that use Cg-compiler-1.2.0402.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CG_COMPILER_1.2.0402_BUILDLINK3_MK:=	${CG_COMPILER_1.2.0402_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Cg-compiler-1.2.0402
.endif

.if !empty(CG_COMPILER_1.2.0402_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=				Cg-compiler-1.2.0402
BUILDLINK_DEPENDS.Cg-compiler-1.2.0402+=	Cg-compiler-1.2.0402>=1900
BUILDLINK_PKGSRCDIR.Cg-compiler-1.2.0402?=	../../wip/Cg-compiler

.endif # CG_COMPILER_1.2.0402_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
