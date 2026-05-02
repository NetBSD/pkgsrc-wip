# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xvega-bindings

.if !defined(XVEGA_BINDINGS_BUILDLINK3_MK)
XVEGA_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xvega-bindings+=	xvega-bindings>=0.1.2
BUILDLINK_PKGSRCDIR.xvega-bindings?=	../../wip/xvega-bindings

.include "../../wip/xvega/buildlink3.mk"

.endif	# XVEGA_BINDINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xvega-bindings
