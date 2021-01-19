# $NetBSD$

BUILDLINK_TREE+=	go-mock

.if !defined(GO_MOCK_BUILDLINK3_MK)
GO_MOCK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mock=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mock?=		build

BUILDLINK_API_DEPENDS.go-mock+=	go-mock>=1.4.4
BUILDLINK_PKGSRCDIR.go-mock?=	../../wip/go-mock

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../textproc/go-goldmark/buildlink3.mk"
.endif	# GO_MOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mock
