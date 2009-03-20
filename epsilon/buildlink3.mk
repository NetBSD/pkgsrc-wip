# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	epsilon

.if !defined(EPSILON_BUILDLINK3_MK)
EPSILON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.epsilon+=	epsilon>=0.3.0.012
BUILDLINK_ABI_DEPENDS.epsilon?=	epsilon>=0.3.0.012nb1
BUILDLINK_PKGSRCDIR.epsilon?=	../../wip/epsilon

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epeg/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.endif # EPSILON_BUILDLINK3_MK

BUILDLINK_TREE+=	-epsilon
