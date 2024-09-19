# $NetBSD: buildlink3.mk,v 1.6 2010/01/17 12:03:33 thomasklausner Exp $

BUILDLINK_TREE+=	xar

.if !defined(XAR_BUILDLINK3_MK)
XAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xar+=	xar>=1.5.2
BUILDLINK_ABI_DEPENDS.xar?=	xar>=1.5.2nb1
BUILDLINK_PKGSRCDIR.xar?=	../../wip/xar

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # XAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-xar
