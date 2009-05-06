# $NetBSD: buildlink3.mk,v 1.7 2009/05/06 09:21:59 cheusov Exp $

BUILDLINK_TREE+=	aolserver4

.if !defined(AOLSERVER4_BUILDLINK3_MK)
AOLSERVER4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aolserver4+=	aolserver>=4.0.7
BUILDLINK_PKGSRCDIR.aolserver4?=	../../wip/aolserver4

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.endif # AOLSERVER4_BUILDLINK3_MK

BUILDLINK_TREE+=	-aolserver4
