# $NetBSD$

BUILDLINK_TREE+=	go-jpillora-backoff

.if !defined(GO_JPILLORA_BACKOFF_BUILDLINK3_MK)
GO_JPILLORA_BACKOFF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jpillora-backoff=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jpillora-backoff?=	build

BUILDLINK_API_DEPENDS.go-jpillora-backoff+=	go-jpillora-backoff>=1.0.0
BUILDLINK_PKGSRCDIR.go-jpillora-backoff?=	../../wip/go-jpillora-backoff
.endif	# GO_JPILLORA_BACKOFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jpillora-backoff
