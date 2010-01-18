# $NetBSD: buildlink3.mk,v 1.4 2010/01/18 09:38:19 thomasklausner Exp $

BUILDLINK_TREE+=	elementary

.if !defined(ELEMENTARY_BUILDLINK3_MK)
ELEMENTARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elementary+=	elementary>=0.5.1.0
BUILDLINK_ABI_DEPENDS.elementary?=	elementary>=0.5.1.0nb2
BUILDLINK_PKGSRCDIR.elementary?=	../../wip/elementary

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.endif	# ELEMENTARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-elementary
