# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	json-c

.if !defined(JSON_C_BUILDLINK3_MK)
JSON_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.7
BUILDLINK_PKGSRCDIR.json-c?=	../../category/json
.endif # JSON_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-c
