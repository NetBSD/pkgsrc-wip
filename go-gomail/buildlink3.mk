# $NetBSD$

BUILDLINK_TREE+=	go-gomail

.if !defined(GO_GOMAIL_BUILDLINK3_MK)
GO_GOMAIL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gomail=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gomail?=		build

BUILDLINK_API_DEPENDS.go-gomail+=	go-gomail>=2.0
BUILDLINK_PKGSRCDIR.go-gomail?=		../../wip/go-gomail
.endif  # GO_GOMAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gomail
