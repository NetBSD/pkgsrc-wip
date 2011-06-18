# $NetBSD: buildlink3.mk,v 1.5 2011/06/18 11:30:50 obache Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-FreeWnn-lib>=1.11alpha22
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../wip/ja-freewnn-lib
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
