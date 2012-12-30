# $NetBSD: buildlink3.mk,v 1.6 2012/12/30 20:00:56 roelants Exp $

BUILDLINK_TREE+=	elementary

.if !defined(ELEMENTARY_BUILDLINK3_MK)
ELEMENTARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elementary+=	elementary>=1.7.0
BUILDLINK_PKGSRCDIR.elementary?=	../../wip/elementary

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
