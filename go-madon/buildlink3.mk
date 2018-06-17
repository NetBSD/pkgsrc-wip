# $NetBSD$

BUILDLINK_TREE+=	go-madon

.if !defined(GO_MADON_BUILDLINK3_MK)
GO_YAML_GHODSS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-madon=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-madon?=		build

BUILDLINK_API_DEPENDS.go-madon+=	go-madon>=0.0
BUILDLINK_PKGSRCDIR.go-madon?=		../../wip/go-madon

.include "../../net/go-websocket/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.include "../../wip/go-rest/buildlink3.mk"
.endif  # GO_MADON_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-madon
