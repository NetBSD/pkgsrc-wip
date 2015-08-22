# $NetBSD: buildlink3.mk,v 1.1 2015/08/22 10:50:16 roelants Exp $

BUILDLINK_TREE+=	elementary

.if !defined(ELEMENTARY_BUILDLINK3_MK)
ELEMENTARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elementary+=	elementary>=1.7.0
BUILDLINK_PKGSRCDIR.elementary?=	../../wip/elementary17

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../wip/eio/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/e_dbus/buildlink3.mk"
.endif	# ELEMENTARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-elementary
