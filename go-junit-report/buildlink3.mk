# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-junit-report

.if !defined(GO_JUNIT_REPORT_BUILDLINK3_MK)
GO_JUNIT_REPORT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-junit-report=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-junit-report?=		build

BUILDLINK_API_DEPENDS.go-junit-report+=	go-junit-report>=1.3.0
BUILDLINK_PKGSRCDIR.go-junit-report?=	../../wip/go-junit-report

.endif  # GO_JUNIT_REPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	go-junit-report
