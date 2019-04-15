# $NetBSD$
BUILDLINK_TREE+=	go-paths-helper

.if !defined(GO_PATHS_HELPER_BUILDLINK3_MK)
GO_PATHS_HELPER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-paths-helper=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-paths-helper?=		build

BUILDLINK_API_DEPENDS.go-paths-helper+=	go-paths-helper>=0
BUILDLINK_PKGSRCDIR.go-paths-helper?=	../../wip/go-paths-helper
.endif	# GO_PATHS_HELPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-paths-helper
