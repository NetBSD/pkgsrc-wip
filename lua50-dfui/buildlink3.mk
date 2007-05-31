# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/05/31 19:31:15 hoka_adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LUADFUI_BUILDLINK3_MK:=	${LUADFUI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	luadfui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nluadfui}
BUILDLINK_PACKAGES+=	luadfui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}luadfui

.if ${LUADFUI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.luadfui+=	luadfui>=0.1
BUILDLINK_PKGSRCDIR.luadfui?=	../../wip/lua50-dfui
.endif	# LUADFUI_BUILDLINK3_MK

.include "../../devel/libaura/buildlink3.mk"
.include "../../wip/libdfui/buildlink3.mk"
.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50-posix/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
