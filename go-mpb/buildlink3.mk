# $NetBSD$

BUILDLINK_TREE+=	go-mpb

.if !defined(GO_MPB_BUILDLINK3_MK)
GO_MPB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mpb=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mpb?=		build

BUILDLINK_API_DEPENDS.go-mpb+=	go-mpb>=5.4.0
BUILDLINK_PKGSRCDIR.go-mpb?=	../../wip/go-mpb

.include "../../devel/go-sys/buildlink3.mk"
.include "../../wip/go-ewma/buildlink3.mk"
.include "../../wip/go-stripansi/buildlink3.mk"
.include "../../textproc/go-runewidth/buildlink3.mk"
.endif	# GO_MPB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mpb
