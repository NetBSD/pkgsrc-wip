# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-GLURaw

.if !defined(HS_GLURAW_BUILDLINK3_MK)
HS_GLURAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-GLURaw+=	hs-GLURaw>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-GLURaw+=	hs-GLURaw>=1.1.0.0
BUILDLINK_PKGSRCDIR.hs-GLURaw?=		../../wip/hs-GLURaw

.include "../../wip/hs-OpenGLRaw/buildlink3.mk"
.endif	# HS_GLURAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-GLURaw
