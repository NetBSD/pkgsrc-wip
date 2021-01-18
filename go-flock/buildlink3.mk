# $NetBSD$

BUILDLINK_TREE+=	go-flock

.if !defined(GO_FLOCK_BUILDLINK3_MK)
GO_FLOCK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-flock=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-flock?=		build

BUILDLINK_API_DEPENDS.go-flock+=	go-flock>=0.8.0
BUILDLINK_PKGSRCDIR.go-flock?=	../../wip/go-flock
.endif	# GO_FLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-flock
