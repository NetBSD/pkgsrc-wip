# $NetBSD: buildlink3.mk,v 1.1 2012/01/27 22:02:38 mwdavies Exp $

BUILDLINK_TREE+=	okular

.if !defined(OKULAR_BUILDLINK3_MK)
OKULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.okular+=	okular>=4.8.0
BUILDLINK_PKGSRCDIR.okular?=	../../wip/okular

.endif	# OKULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-okular
