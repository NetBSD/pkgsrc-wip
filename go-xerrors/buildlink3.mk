# $NetBSD$

BUILDLINK_TREE+=	go-xerrors

.if !defined(GO_XERRORS_BUILDLINK3_MK)
GO_XERRORS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-xerrors=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-xerrors?=		build

BUILDLINK_API_DEPENDS.go-xerrors+=	go-xerrors>=20190719
BUILDLINK_PKGSRCDIR.go-xerrors?=	../../wip/go-xerrors
.endif	# GO_XERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-xerrors
