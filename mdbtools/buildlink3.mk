# $NetBSD: buildlink3.mk,v 1.1 2012/05/02 08:21:29 noud4 Exp $

BUILDLINK_TREE+=	mdbtools

.if !defined(MDBTOOLS_BUILDLINK3_MK)
MDBTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdbtools+=	mdbtools>=0.6pre1
BUILDLINK_ABI_DEPENDS.mdbtools+=	mdbtools>=0.6pre1
BUILDLINK_PKGSRCDIR.mdbtools?=		../../wip/mdbtools

.include "../../devel/glib2/buildlink3.mk"
.endif # MDBTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdbtools
