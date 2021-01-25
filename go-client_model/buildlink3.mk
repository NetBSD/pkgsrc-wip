# $NetBSD$

BUILDLINK_TREE+=	go-client_model

.if !defined(GO_CLIENT_MODEL_BUILDLINK3_MK)
GO_CLIENT_MODEL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-client_model=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-client_model?=		build

BUILDLINK_API_DEPENDS.go-client_model+=	go-client_model>=0.2.0
BUILDLINK_PKGSRCDIR.go-client_model?=	../../wip/go-client_model

.include "../../devel/go-protobuf/buildlink3.mk"
.endif	# GO_CLIENT_MODEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-client_model
