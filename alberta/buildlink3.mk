# $NetBSD: buildlink3.mk,v 1.1.1.2 2012/03/22 19:26:19 outpaddling Exp $

BUILDLINK_TREE+=	alberta

.if !defined(ALBERTA_BUILDLINK3_MK)
ALBERTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alberta+=	alberta>=2.0.1
BUILDLINK_PKGSRCDIR.alberta?=	../../jb-wip/alberta

.include "../../math/blas/buildlink3.mk"
.endif	# ALBERTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-alberta
