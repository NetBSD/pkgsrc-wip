# $NetBSD$

BUILDLINK_TREE+=	go-native

.if !defined(GO_NATIVE_BUILDLINK3_MK)
GO_NATIVE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-native=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-native?=		build

BUILDLINK_API_DEPENDS.go-native+=	go-native>=20200817
BUILDLINK_PKGSRCDIR.go-native?=	../../wip/go-native
.endif	# GO_NATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-native
