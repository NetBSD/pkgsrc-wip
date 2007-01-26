# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/26 17:12:11 mrohrer Exp $

BUILDLINK_DEPTH:=               ${BUILDLINK_DEPTH}+
GGZ_LIBGGZ_BUILDLINK3_MK:=      ${GGZ_LIBGGZ_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=     ggz-libggz
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Nggz-libggz}
BUILDLINK_PACKAGES+=    ggz-libggz
BUILDLINK_ORDER:=       ${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ggz-libggz

.if ${GGZ_LIBGGZ_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ggz-libggz+=      ggz-libggz>=0.0.14
BUILDLINK_PKGSRCDIR.ggz-libggz?=        ../../wip/ggz-libggz
.endif  # GGZ_LIBGGZ_BUILDLINK3_MK

BUILDLINK_DEPTH:=               ${BUILDLINK_DEPTH:S/+$//}
