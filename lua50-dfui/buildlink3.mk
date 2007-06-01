# $NetBSD: buildlink3.mk,v 1.2 2007/06/01 18:00:09 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LUA50_DFUI_BUILDLINK3_MK:=	${LUA50_DFUI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	lua50-dfui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlua50-dfui}
BUILDLINK_PACKAGES+=	lua50-dfui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lua50-dfui

.if ${LUA50_DFUI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.lua50-dfui+=	lua50-dfui>=0.1
BUILDLINK_PKGSRCDIR.lua50-dfui?=	../../wip/lua50-dfui
.endif	# LUA50_DFUI_BUILDLINK3_MK

.include "../../devel/libaura/buildlink3.mk"
.include "../../wip/libdfui/buildlink3.mk"
.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50-posix/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
