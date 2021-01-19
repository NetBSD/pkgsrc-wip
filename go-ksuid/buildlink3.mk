# $NetBSD$

BUILDLINK_TREE+=	go-ksuid

.if !defined(GO_KSUID_BUILDLINK3_MK)
GO_KSUID_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ksuid=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ksuid?=		build

BUILDLINK_API_DEPENDS.go-ksuid+=	go-ksuid>=1.0.3
BUILDLINK_PKGSRCDIR.go-ksuid?=	../../wip/go-ksuid
.endif	# GO_KSUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ksuid
