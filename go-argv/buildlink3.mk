# $NetBSD$

BUILDLINK_TREE+=	go-argv

.if !defined(GO_ARGV_BUILDLINK3_MK)
GO_ARGV_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-argv=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-argv?=		build

BUILDLINK_API_DEPENDS.go-argv+=	go-argv>=1.3.0
BUILDLINK_PKGSRCDIR.go-argv?=		../../wip/go-argv
.endif	# GO_ARGV_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-argv
