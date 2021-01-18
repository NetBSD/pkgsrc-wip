# $NetBSD$

BUILDLINK_TREE+=	go-maligned

.if !defined(GO_MALIGNED_BUILDLINK3_MK)
GO_MALIGNED_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-maligned=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-maligned?=		build

BUILDLINK_API_DEPENDS.go-maligned+=	go-maligned>=20180606
BUILDLINK_PKGSRCDIR.go-maligned?=	../../wip/go-maligned

.include "../../devel/go-tools/buildlink3.mk"
.endif	# GO_MALIGNED_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-maligned
