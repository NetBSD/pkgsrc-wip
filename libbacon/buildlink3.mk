# $NetBSD: buildlink3.mk,v 1.2 2013/08/14 01:33:35 outpaddling Exp $

BUILDLINK_TREE+=	libbacon

.if !defined(LIBBACON_BUILDLINK3_MK)
LIBBACON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbacon+=	libbacon>=1.2.2
BUILDLINK_PKGSRCDIR.libbacon?=		../../wip/libbacon
BUILDLINK_DEPMETHOD.libbacon?=		build
.endif	# LIBBACON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbacon
