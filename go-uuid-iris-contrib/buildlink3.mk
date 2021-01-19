# $NetBSD$

BUILDLINK_TREE+=	go-uuid-iris-contrib

.if !defined(GO_UUID_IRIS_CONTRIB_BUILDLINK3_MK)
GO_UUID_IRIS_CONTRIB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-uuid-iris-contrib=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-uuid-iris-contrib?=	build

BUILDLINK_API_DEPENDS.go-uuid-iris-contrib+=	go-uuid-iris-contrib>=2.0.0
BUILDLINK_PKGSRCDIR.go-uuid-iris-contrib?=	../../wip/go-uuid-iris-contrib
.endif	# GO_UUID_IRIS_CONTRIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-uuid-iris-contrib
