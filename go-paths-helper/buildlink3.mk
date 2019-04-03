# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-paths-helper

.if !defined(GO_PATHS_HELPER_BUILDLINK3_MK)
GO_PATHS_HELPER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-paths-helper=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-paths-helper?=	build

#UILDLINK_API_DEPENDS.go-paths-helper+=	go-paths-helper>=1.3.0
BUILDLINK_PKGSRCDIR.go-paths-helper?=	../../wip/go-paths-helper

.endif  # GO_PATHS_HELPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-paths-helper
