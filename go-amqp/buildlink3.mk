# $NetBSD$

BUILDLINK_TREE+=	go-amqp

.if !defined(GO_AMQP_BUILDLINK3_MK)
GO_AMQP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-amqp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-amqp?=		build

BUILDLINK_API_DEPENDS.go-amqp+=	go-amqp>=1.0.0
BUILDLINK_PKGSRCDIR.go-amqp?=	../../wipy/go-amqp
.endif	# GO_AMQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-amqp
