# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/11/13 10:05:17 fhajny Exp $

BUILDLINK_TREE+=			rabbitmq

.if !defined(RABBITMQ_BUILDLINK3_MK)
RABBITMQ_BUILDLINK3_MK:=

.include "version.mk"

BUILDLINK_API_DEPENDS.rabbitmq+=	rabbitmq>=1.5.0
BUILDLINK_PKGSRCDIR.rabbitmq?=		../../wip/rabbitmq

BUILDLINK_INCDIRS.rabbitmq?=		lib/erlang/lib/rabbitmq-${RMQ_VERSION}/include

#.include "../../lang/erlang/buildlink3.mk"
.endif	# RABBITMQ_BUILDLINK3_MK

BUILDLINK_TREE+=			-rabbitmq
