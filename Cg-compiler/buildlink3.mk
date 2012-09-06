# $NetBSD: buildlink3.mk,v 1.4 2012/09/06 13:06:37 othyro Exp $

BUILDLINK_TREE+=	Cg-compiler

.if !defined(CG_COMPILER_BUILDLINK3_MK)
CG_COMPILER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Cg-compiler+=	Cg-compiler>=3.1
BUILDLINK_PKGSRCDIR.Cg-compiler?=	../../wip/Cg-compiler
.endif	# CG_COMPILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-Cg-compiler
