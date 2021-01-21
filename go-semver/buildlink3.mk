# $NetBSD$

BUILDLINK_TREE+=	go-semver

.if !defined(GO_SEMVER_BUILDLINK3_MK)
GO_SEMVER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-semver=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-semver?=		build

BUILDLINK_API_DEPENDS.go-semver+=	go-semver>=3.1.1
BUILDLINK_PKGSRCDIR.go-semver?=		../../wip/go-semver
.endif	# GO_SEMVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-semver
