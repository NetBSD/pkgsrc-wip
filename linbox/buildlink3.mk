# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/20 22:45:12 jihbed Exp $

BUILDLINK_TREE+=	linbox

.if !defined(LINBOX_BUILDLINK3_MK)
LINBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linbox+=	linbox>=1.1.7
BUILDLINK_PKGSRCDIR.linbox?=	../../wip/linbox


.include "../../mk/blas.buildlink3.mk"
.include "../../wip/givaro/buildlink3.mk"
.endif	# LINBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-linbox
