
# $NetBSD$

BUILDLINK_TREE+=        go-resty

.if !defined(GO_RESTY_BUILDLINK3_MK)
GO_RESTY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-resty=     ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-resty?=          build

BUILDLINK_API_DEPENDS.go-resty+=        go-resty>=2.3.0
BUILDLINK_PKGSRCDIR.go-resty?=  ../../wip/go-resty

.include "../../net/go-net/buildlink3.mk"
.endif  # GO_RESTY_BUILDLINK3_MK

BUILDLINK_TREE+=        -go-resty
