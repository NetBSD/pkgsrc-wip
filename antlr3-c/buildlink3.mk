# $NetBSD: buildlink3.mk,v 1.2 2013/03/07 11:54:12 othyro Exp $

BUILDLINK_TREE+=	antlr3-c

.if !defined(ANTLR3_C_BUILDLINK3_MK)
ANTLR3_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.antlr3-c+=	antlr3-c>=3.4
BUILDLINK_PKGSRCDIR.antlr3-c?=		../../wip/antlr3-c
.endif	# ANTLR3_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-antlr3-c
