# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xeus-zmq

.if !defined(XEUS_ZMQ_BUILDLINK3_MK)
XEUS_ZMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xeus-zmq+=	xeus-zmq>=4.0.0
BUILDLINK_PKGSRCDIR.xeus-zmq?=		../../wip/xeus-zmq

.include "../../net/zeromq/buildlink3.mk"
.include "../../net/cppzmq/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"

.endif	# XEUS_ZMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-xeus-zmq
