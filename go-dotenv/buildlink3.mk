# $NetBSD$

BUILDLINK_TREE+=	go-dotenv

.if !defined(GO_DOTENV_BUILDLINK3_MK)
GO_DOTENV_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-dotenv=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-dotenv?=		build

BUILDLINK_API_DEPENDS.go-dotenv+=	go-dotenv>=20180121
BUILDLINK_PKGSRCDIR.go-dotenv?=		../../wip/go-dotenv
.endif	# GO_DOTENV_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-dotenv
