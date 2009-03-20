# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	eventlog

.if !defined(EVENTLOG_BUILDLINK3_MK)
EVENTLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eventlog+=	eventlog>=0.2.5
BUILDLINK_PKGSRCDIR.eventlog?=	../../wip/eventlog
.endif # EVENTLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-eventlog
