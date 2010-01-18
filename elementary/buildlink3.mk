# $NetBSD: buildlink3.mk,v 1.5 2010/01/18 19:41:05 jsonn Exp $

BUILDLINK_TREE+=	elementary

.if !defined(ELEMENTARY_BUILDLINK3_MK)
ELEMENTARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elementary+=	elementary>=0.6.0.63
BUILDLINK_PKGSRCDIR.elementary?=	../../wip/elementary

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.endif	# ELEMENTARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-elementary
