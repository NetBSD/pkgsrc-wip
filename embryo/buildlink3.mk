# $NetBSD: buildlink3.mk,v 1.8 2012/12/30 19:43:00 roelants Exp $

BUILDLINK_TREE+=	embryo

.if !defined(EMBRYO_BUILDLINK3_MK)
EMBRYO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.embryo+=	embryo>=1.7.0
BUILDLINK_PKGSRCDIR.embryo?=	../../wip/embryo

.include "../../wip/eina/buildlink3.mk"
.endif # EMBRYO_BUILDLINK3_MK

BUILDLINK_TREE+=	-embryo
