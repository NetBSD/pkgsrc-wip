# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/01 20:11:56 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LUA50_APP_BUILDLINK3_MK:=	${LUA50_APP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	lua50-app
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlua50-app}
BUILDLINK_PACKAGES+=	lua50-app
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lua50-app

.if ${LUA50_APP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.lua50-app+=	lua50-app>=0.1
BUILDLINK_PKGSRCDIR.lua50-app?=	../../wip/lua50-app
.endif	# LUA50_APP_BUILDLINK3_MK

.include "../../wip/lua50-posix/buildlink3.mk"
.include "../../wip/lua50-filename/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
