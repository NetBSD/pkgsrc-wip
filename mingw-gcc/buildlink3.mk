# $NetBSD: buildlink3.mk,v 1.1 2004/05/10 22:04:39 blef Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MINGW_GCC_BUILDLINK3_MK:=	${MINGW_GCC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-gcc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-gcc}
BUILDLINK_PACKAGES+=	mingw-gcc

.if !empty(MINGW_GCC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mingw-gcc+=	mingw-gcc>=3.3.1
BUILDLINK_PKGSRCDIR.mingw-gcc?=	../../wip/mingw-gcc
.endif	# MINGW_GCC_BUILDLINK3_MK

.include "../../wip/mingw-binutils/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
