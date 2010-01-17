# $NetBSD: buildlink3.mk,v 1.10 2010/01/17 12:03:25 thomasklausner Exp $

BUILDLINK_TREE+=	esmart

.if !defined(ESMART_BUILDLINK3_MK)
ESMART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.esmart+=	esmart>=0.9.0.42nb2
BUILDLINK_ABI_DEPENDS.esmart?=	esmart>=0.9.0.042nb3
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
