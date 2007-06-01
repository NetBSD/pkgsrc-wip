# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/01 20:13:26 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LUA50_FILENAME_BUILDLINK3_MK:=	${LUA50_FILENAME_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	lua50-filename
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlua50-filename}
BUILDLINK_PACKAGES+=	lua50-filename
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lua50-filename

.if ${LUA50_FILENAME_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.lua50-filename+=	lua50-filename>=0.1
BUILDLINK_PKGSRCDIR.lua50-filename?=	../../wip/lua50-filename
.endif	# LUA50_FILENAME_BUILDLINK3_MK

.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50-posix/buildlink3.mk"
.include "../../wip/lua50/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
