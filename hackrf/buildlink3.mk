# $NetBSD: buildlink3.mk,v 1.1 2014/10/03 08:00:44 makoto Exp $

BUILDLINK_TREE+=	hackrf

.if !defined(HACKRF_BUILDLINK3_MK)
HACKRF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hackrf+=	hackrf>=0.1
BUILDLINK_ABI_DEPENDS.hackrf+=	hackrf>=0.1
BUILDLINK_PKGSRCDIR.hackrf?=		../../wip/hackrf
.endif # HACKRF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hackrf
