# $NetBSD: buildlink3.mk,v 1.0 2024/11/14 16:30:00 dkazankov Exp $

BUILDLINK_TREE+=	polyorb

.if !defined(POLYORB_BUILDLINK3_MK)
POLYORB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polyorb+=	polyorb>=25.0
BUILDLINK_PKGSRCDIR.polyorb=	../../wip/polyorb
BUILDLINK_DEPMETHOD.polyorb?=	build

BUILDLINK_AUTO_VARS.polyorb=	no
BUILDLINK_AUTO_DIRS.polyorb=	no

.endif

BUILDLINK_TREE+=	-polyorb
