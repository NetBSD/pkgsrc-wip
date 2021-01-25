# $NetBSD$

BUILDLINK_TREE+=	go-faker

.if !defined(GO_FAKER_BUILDLINK3_MK)
GO_FAKER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-faker=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-faker?=		build

BUILDLINK_API_DEPENDS.go-faker+=	go-faker>=20171103
BUILDLINK_PKGSRCDIR.go-faker?=		../../category/go-faker

.include "../../devel/go-yaml/buildlink3.mk"
.endif	# GO_FAKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-faker
