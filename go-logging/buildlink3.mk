# $NetBSD$

BUILDLINK_TREE+=	go-logging

.if !defined(GO_LOGGING_BUILDLINK3_MK)
GO_LOGGING_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-logging=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-logging?=	build

BUILDLINK_API_DEPENDS.go-logging+=	go-logging>=20201216
BUILDLINK_PKGSRCDIR.go-logging?=	../../wip/go-logging
.endif	# GO_LOGGING_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-logging
