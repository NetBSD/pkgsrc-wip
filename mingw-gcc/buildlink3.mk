# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	mingw-gcc

.include "../../wip/mingw/Makefile.common"

BUILDLINK_API_DEPENDS.mingw-gcc+=	mingw-gcc>=3.4.2
BUILDLINK_PKGSRCDIR.mingw-gcc?=	../../wip/mingw-gcc
BUILDLINK_FNAME_TRANSFORM.mingw-gcc+=	-e "s,${MINGW_TARGET}/lib,lib/,g"

.include "../../wip/mingw-binutils/buildlink3.mk"
.endif # MINGW_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-gcc
