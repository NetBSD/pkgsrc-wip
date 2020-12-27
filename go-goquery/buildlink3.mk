# $NetBSD$

BUILDLINK_TREE+=        go-goquery

.if !defined(GO_GOQUERY_BUILDLINK3_MK)
GO_GOQUERY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goquery=   ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goquery?=                build

BUILDLINK_API_DEPENDS.go-goquery+=      go-goquery>=1.6.0
BUILDLINK_PKGSRCDIR.go-goquery?=        ../../wip/go-goquery
.endif  # GO_GOQUERY_BUILDLINK3_MK

BUILDLINK_TREE+=        -go-goquery
