# $NetBSD: buildlink3.mk,v 1.1 2020/12/31 14:34:12 jihbed Exp $

BUILDLINK_TREE+=	go-concurrent

.if !defined(GO_CONCURRENT_BUILDLINK3_MK)
GO_CONCURRENT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-concurrent=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-concurrent?=		build

BUILDLINK_API_DEPENDS.go-concurrent+=	go-concurrent>=20180306
BUILDLINK_PKGSRCDIR.go-concurrent?=	../../wip/go-current
.endif	# GO_CONCURRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-concurrent
