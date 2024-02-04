# $NetBSD$

BUILDLINK_TREE+=	opendbx

.if !defined(OPENDBX_BUILDLINK3_MK)
OPENDBX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opendbx+=	opendbx>=1.4.6
BUILDLINK_PKGSRCDIR.opendbx?=	../../devel/opendbx

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif	# OPENDBX_BUILDLINK3_MK

BUILDLINK_TREE+=	-opendbx
