# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/01 20:16:15 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DFUIBE_LUA_BUILDLINK3_MK:=	${DFUIBE_LUA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	dfuibe_lua
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndfuibe_lua}
BUILDLINK_PACKAGES+=	dfuibe_lua
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dfuibe_lua

.if ${DFUIBE_LUA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.dfuibe_lua+=	dfuibe_lua>=1.0
BUILDLINK_PKGSRCDIR.dfuibe_lua?=	../../wip/dfuibe_lua
.endif	# DFUIBE_LUA_BUILDLINK3_MK

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-pty/buildlink3.mk"
.include "../../wip/lua50-dfui/buildlink3.mk"
.include "../../wip/lua50-app/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
