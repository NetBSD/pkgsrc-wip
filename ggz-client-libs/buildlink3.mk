# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/26 17:13:28 mrohrer Exp $

BUILDLINK_DEPTH:=               ${BUILDLINK_DEPTH}+
GGZ_CLIENT_LIBS_BUILDLINK3_MK:= ${GGZ_CLIENT_LIBS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=     ggz-client-libs
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Nggz-client-libs}
BUILDLINK_PACKAGES+=    ggz-client-libs
BUILDLINK_ORDER:=       ${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ggz-client-libs

.if ${GGZ_CLIENT_LIBS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ggz-client-libs+= ggz-client-libs>=0.0.14
BUILDLINK_PKGSRCDIR.ggz-client-libs?=   ../../wip/ggz-client-libs
.endif  # GGZ_CLIENT_LIBS_BUILDLINK3_MK

.include "../../wip/ggz-libggz/buildlink3.mk"

BUILDLINK_DEPTH:=               ${BUILDLINK_DEPTH:S/+$//}

