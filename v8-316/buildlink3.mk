# $NetBSD: buildlink3.mk,v 1.2 2014/01/28 15:46:59 fhajny Exp $

BUILDLINK_TREE+=	v8

.if !defined(V8_BUILDLINK3_MK)
V8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.v8+=	v8>=3.16.0<3.17
BUILDLINK_ABI_DEPENDS.v8+=	v8>=3.16.0<3.17
BUILDLINK_PKGSRCDIR.v8?=	../../wip/v8-316

.include "../../mk/readline.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-v8
