# $NetBSD$

BUILDLINK_TREE+=	go-rtp

.if !defined(GO_RTP_BUILDLINK3_MK)
GO_RTP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-rtp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-rtp?=		build

BUILDLINK_API_DEPENDS.go-rtp+=	go-rtp>=1.6.2
BUILDLINK_PKGSRCDIR.go-rtp?=	../../wip/pgo-rtp

.include "../../wip/go-randutil/buildlink3.mk"
.endif	# GO_RTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-rtp
