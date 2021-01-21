# $NetBSD$

BUILDLINK_TREE+=	go-flaggy

.if !defined(GO_FLAGGY_BUILDLINK3_MK)
GO_FLAGGY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-flaggy=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-flaggy?=		build

BUILDLINK_API_DEPENDS.go-flaggy+=	go-flaggy>=1.4.4
BUILDLINK_PKGSRCDIR.go-flaggy?=		../../wip/go-flaggy
.endif	# GO_FLAGGY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-flaggy
