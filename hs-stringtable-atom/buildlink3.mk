# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stringtable-atom

.if !defined(HS_STRINGTABLE_ATOM_BUILDLINK3_MK)
HS_STRINGTABLE_ATOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringtable-atom+=	hs-stringtable-atom>=0.0.6
BUILDLINK_ABI_DEPENDS.hs-stringtable-atom+=	hs-stringtable-atom>=0.0.6.1
BUILDLINK_PKGSRCDIR.hs-stringtable-atom?=	../../wip/hs-stringtable-atom

.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_STRINGTABLE_ATOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringtable-atom
