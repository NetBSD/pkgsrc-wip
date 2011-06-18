# $NetBSD: buildlink3.mk,v 1.4 2011/06/18 02:59:38 obache Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-freewnn-lib>=1.11alpha22
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../wip/ja-freewnn-lib
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
