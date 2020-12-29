# $NetBSD$

BUILDLINK_TREE+=	go-opentracing

.if !defined(GO_OPENTRACING_BUILDLINK3_MK)
GO_OPENTRACING_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-opentracing=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-opentracing?=		build

BUILDLINK_API_DEPENDS.go-opentracing+=	go-opentracing>=1.2.0
BUILDLINK_PKGSRCDIR.go-opentracing?=	../../wip/go-opentracing

.include "../../devel/go-testify/buildlink3.mk"
.endif	# GO_OPENTRACING_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-opentracing
