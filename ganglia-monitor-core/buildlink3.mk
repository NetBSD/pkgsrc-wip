# $NetBSD: buildlink3.mk,v 1.1 2015/04/06 20:57:30 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ganglia-monitor-core-?=	build

BUILDLINK_TREE+=	ganglia-monitor-core-

.if !defined(GANGLIA_MONITOR_CORE__BUILDLINK3_MK)
GANGLIA_MONITOR_CORE__BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ganglia-monitor-core-+=	ganglia-monitor-core->=3.6.0
BUILDLINK_PKGSRCDIR.ganglia-monitor-core-?=	../../wip/ganglia-monitor-core
.endif	# GANGLIA_MONITOR_CORE__BUILDLINK3_MK

BUILDLINK_TREE+=	-ganglia-monitor-core-
