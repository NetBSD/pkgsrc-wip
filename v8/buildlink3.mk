# $NetBSD: buildlink3.mk,v 1.1 2014/01/28 15:40:47 fhajny Exp $

BUILDLINK_TREE+=	v8

.if !defined(V8_BUILDLINK3_MK)
V8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.v8+=	v8>=3.21.0
BUILDLINK_ABI_DEPENDS.v8+=	v8>=3.21.0
BUILDLINK_PKGSRCDIR.v8?=	../../wip/v8

.include "../../mk/readline.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-v8
