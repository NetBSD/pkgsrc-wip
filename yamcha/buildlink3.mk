# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:57 jsonn Exp $

BUILDLINK_TREE+=	yamcha

.if !defined(YAMCHA_BUILDLINK3_MK)
YAMCHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=0.33
BUILDLINK_PKGSRCDIR.yamcha?=	../../wip/yamcha

.include "../../wip/TinySVM/buildlink3.mk"
.endif # YAMCHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-yamcha
