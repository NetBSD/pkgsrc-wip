# $NetBSD$

BUILDLINK_TREE+=	go-stripansi

.if !defined(GO_STRIPANSI_BUILDLINK3_MK)
GO_STRIPANSI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-stripansi=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-stripansi?=	build

BUILDLINK_API_DEPENDS.go-stripansi+=	go-stripansi>=20180116
BUILDLINK_PKGSRCDIR.go-stripansi?=	../../wip/go-stripansi
.endif	# GO_STRIPANSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-stripansi
