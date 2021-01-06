# $NetBSD$

BUILDLINK_TREE+=	go-flac-eaburns

.if !defined(GO_FLAC_EABURNS_BUILDLINK3_MK)
GO_FLAC_EABURNS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-flac-eaburns=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-flac-eaburns?=		build

BUILDLINK_API_DEPENDS.go-flac-eaburns+=	go-flac-eaburns>=20170903
BUILDLINK_PKGSRCDIR.go-flac-eaburns?=	../../wip/go-flac-eaburns

.include "../../wip/go-bit/buildlink3.mk"
.endif	# GO_FLAC_EABURNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-flac-eaburns
