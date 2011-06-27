# $NetBSD: buildlink3.mk,v 1.1 2011/06/27 16:08:44 keckhardt Exp $

BUILDLINK_TREE+=	cloog

.if !defined(CLOOG_BUILDLINK3_MK)
CLOOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cloog+=	cloog>=0.16.2
BUILDLINK_ABI_DEPENDS.cloog?=	cloog>=0.16.2
BUILDLINK_PKGSRCDIR.cloog?=	../../wip/cloog

.endif # CLOOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-cloog
