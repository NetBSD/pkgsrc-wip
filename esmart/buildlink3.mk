# $NetBSD: buildlink3.mk,v 1.13 2010/12/26 05:01:22 davesainty Exp $

BUILDLINK_TREE+=	esmart

.if !defined(ESMART_BUILDLINK3_MK)
ESMART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.esmart+=	esmart>=0.9.0.42nb2
BUILDLINK_ABI_DEPENDS.esmart?=	esmart>=0.9.0.042nb5
BUILDLINK_PKGSRCDIR.esmart?=	../../wip/esmart

.include "../../wip/ecore/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # ESMART_BUILDLINK3_MK

BUILDLINK_TREE+=	-esmart
