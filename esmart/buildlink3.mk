BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ESMART_BUILDLINK3_MK:=	${ESMART_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	esmart
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nesmart}
BUILDLINK_PACKAGES+=	esmart
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}esmart

.if ${ESMART_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.esmart+=	esmart>=0.9.0.042nb1
BUILDLINK_PKGSRCDIR.esmart?=	../../wip/esmart
.endif	# ESMART_BUILDLINK3_MK

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
