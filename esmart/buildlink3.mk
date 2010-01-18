# $NetBSD: buildlink3.mk,v 1.11 2010/01/18 09:38:20 thomasklausner Exp $

BUILDLINK_TREE+=	esmart

.if !defined(ESMART_BUILDLINK3_MK)
ESMART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.esmart+=	esmart>=0.9.0.42nb2
BUILDLINK_ABI_DEPENDS.esmart?=	esmart>=0.9.0.042nb4
BUILDLINK_PKGSRCDIR.esmart?=	../../wip/esmart

.include "../../wip/ecore/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # ESMART_BUILDLINK3_MK

BUILDLINK_TREE+=	-esmart
