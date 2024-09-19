# $NetBSD: buildlink3.mk,v 1.1 2013/01/23 02:16:00 noud4 Exp $

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.8.0
BUILDLINK_ABI_DEPENDS.xerces-c?=	xerces-c>=2.8.0
BUILDLINK_PKGSRCDIR.xerces-c?=		../../wip/xerces-c-2.8.0

.include "../../converters/libiconv/buildlink3.mk"
.endif # XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
