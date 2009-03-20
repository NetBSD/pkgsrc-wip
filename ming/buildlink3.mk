# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	ming

.if !defined(MING_BUILDLINK3_MK)
MING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ming+=	ming>=0.4.0beta5
BUILDLINK_PKGSRCDIR.ming?=	../../wip/ming

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif # MING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ming
