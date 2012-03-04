# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/04 07:34:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-stringtable-atom

.if !defined(HS_STRINGTABLE_ATOM_BUILDLINK3_MK)
HS_STRINGTABLE_ATOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringtable-atom+=	hs-stringtable-atom>=0.0.6
BUILDLINK_PKGSRCDIR.hs-stringtable-atom?=	../../wip/hs-stringtable-atom

.include "../../wip/hs-syb/buildlink3.mk"
.endif	# HS_STRINGTABLE_ATOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringtable-atom
