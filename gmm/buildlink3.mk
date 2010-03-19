# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/19 21:06:22 jihbed Exp $

BUILDLINK_TREE+=	gmm

.if !defined(GMM_BUILDLINK3_MK)
GMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmm+=	gmm>=4.0.0
BUILDLINK_PKGSRCDIR.gmm?=	../../wip/gmm
.endif	# GMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmm
