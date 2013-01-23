# $NetBSD: buildlink3.mk,v 1.1 2013/01/23 02:17:06 noud4 Exp $

BUILDLINK_TREE+=	xalan-c

.if !defined(XALAN_C_BUILDLINK3_MK)
XALAN_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xalan-c+=	xalan-c>=1.6nb3
BUILDLINK_ABI_DEPENDS.xalan-c?=	xalan-c>=1.10nb3
BUILDLINK_PKGSRCDIR.xalan-c?=	../../wip/xalan-c

.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/xerces-c-2.8.0/buildlink3.mk"
.endif # XALAN_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xalan-c
