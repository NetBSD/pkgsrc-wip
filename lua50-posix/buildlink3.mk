# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/05/31 19:34:24 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LUA50_POSIX_BUILDLINK3_MK:=	${LUA50_POSIX_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	lua50-posix
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlua50-posix}
BUILDLINK_PACKAGES+=	lua50-posix
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lua50-posix

.if ${LUA50_POSIX_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.lua50-posix+=	lua50-posix>=1.0
BUILDLINK_PKGSRCDIR.lua50-posix?=	../../wip/lua50-posix
.endif	# LUA50_POSIX_BUILDLINK3_MK

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
