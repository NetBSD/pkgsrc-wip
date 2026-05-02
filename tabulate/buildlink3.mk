# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	tabulate

.if !defined(TABULATE_BUILDLINK3_MK)
TABULATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tabulate+=	tabulate>=1.5
BUILDLINK_DEPMETHOD.tabulate?=		build
BUILDLINK_PKGSRCDIR.tabulate?=		../../wip/tabulate

.endif	# TABULATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tabulate
