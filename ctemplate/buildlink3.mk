# $NetBSD: buildlink3.mk,v 1.1 2010/04/20 22:17:33 othyro Exp $

BUILDLINK_TREE+=	ctemplate

.if !defined(CTEMPLATE_BUILDLINK3_MK)
CTEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ctemplate+=	ctemplate>=0.97
BUILDLINK_PKGSRCDIR.ctemplate?=		../../wip/ctemplate
.endif # CTEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ctemplate
