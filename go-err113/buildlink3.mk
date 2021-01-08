# $NetBSD$

BUILDLINK_TREE+=	go-err113

.if !defined(GO_ERR113_BUILDLINK3_MK)
GO_ERR113_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-err113=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-err113?=		build

BUILDLINK_API_DEPENDS.go-err113+=	go-err113>=0.1.0
BUILDLINK_PKGSRCDIR.go-err113?=		../../wip/go-err113

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.endif	# GO_ERR113_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-err113
