# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:35 rillig Exp $

BUILDLINK_TREE+=	xmlada

.if !defined(XMLADA_BUILDLINK3_MK)
XMLADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlada+=	xmlada>21.0.0
BUILDLINK_PKGSRCDIR.xmlada?=	../../wip/xmlada

.endif	# XMLADA_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlada
