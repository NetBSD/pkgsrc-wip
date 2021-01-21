# $NetBSD$

BUILDLINK_TREE+=	go-jettison

.if !defined(GO_JETTISON_BUILDLINK3_MK)
GO_JETTISON_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jettison=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jettison?=		build

BUILDLINK_API_DEPENDS.go-jettison+=	go-jettison>=0.7.1
BUILDLINK_PKGSRCDIR.go-jettison?=	../../wip/go-jettison
.endif	# GO_JETTISON_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jettison
