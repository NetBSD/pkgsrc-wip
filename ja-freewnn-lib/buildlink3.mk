# $NetBSD: buildlink3.mk,v 1.2 2011/06/01 15:57:33 makoto Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-freewnn-lib>=1.1.1
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../wip/ja-freewnn-lib
BUILDLINK_DEPMETHOD.ja-FreeWnn-lib?=	build
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
