# $NetBSD: buildlink3.mk,v 1.3 2004/11/30 18:10:24 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MINGW_GCC_BUILDLINK3_MK:=	${MINGW_GCC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-gcc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-gcc}
BUILDLINK_PACKAGES+=	mingw-gcc

.include "../../wip/mingw/Makefile.common"

.if !empty(MINGW_GCC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mingw-gcc+=	mingw-gcc>=3.4.2
BUILDLINK_PKGSRCDIR.mingw-gcc?=	../../wip/mingw-gcc
BUILDLINK_TRANSFORM.mingw-gcc+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_GCC_BUILDLINK3_MK

.include "../../wip/mingw-binutils/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
