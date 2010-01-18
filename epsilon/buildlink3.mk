# $NetBSD: buildlink3.mk,v 1.8 2010/01/18 09:38:20 thomasklausner Exp $

BUILDLINK_TREE+=	epsilon

.if !defined(EPSILON_BUILDLINK3_MK)
EPSILON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.epsilon+=	epsilon>=0.3.0.012
BUILDLINK_ABI_DEPENDS.epsilon?=	epsilon>=0.3.0.012nb3
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
