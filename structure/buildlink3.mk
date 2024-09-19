# $NetBSD: buildlink3.mk,v 1.1 2014/06/12 12:11:05 outpaddling Exp $

BUILDLINK_TREE+=	structure

.if !defined(STRUCTURE_BUILDLINK3_MK)
STRUCTURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.structure+=	structure>=2.3.4
BUILDLINK_PKGSRCDIR.structure?=		../../wip/structure
.endif	# STRUCTURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-structure
