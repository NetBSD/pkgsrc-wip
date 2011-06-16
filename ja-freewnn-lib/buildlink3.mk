# $NetBSD: buildlink3.mk,v 1.3 2011/06/16 03:08:54 makoto Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-freewnn-lib>=1.11alpha22
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../wip/ja-freewnn-lib
BUILDLINK_DEPMETHOD.ja-FreeWnn-lib?=	build
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
