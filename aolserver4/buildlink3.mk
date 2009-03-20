# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	aolserver4

BUILDLINK_API_DEPENDS.aolserver4+=		aolserver>=4.0.7
BUILDLINK_PKGSRCDIR.aolserver4?=	../../wip/aolserver4

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.endif # AOLSERVER4_BUILDLINK3_MK

BUILDLINK_TREE+=	-aolserver4
