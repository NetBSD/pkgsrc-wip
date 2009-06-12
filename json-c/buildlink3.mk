# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/12 21:12:30 jihbed Exp $

BUILDLINK_TREE+=	json-c

.if !defined(JSON_C_BUILDLINK3_MK)
JSON_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.8
BUILDLINK_PKGSRCDIR.json-c?=	../../wip/json-c
.endif	# JSON_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-c
