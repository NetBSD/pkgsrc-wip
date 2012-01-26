# $NetBSD: buildlink3.mk,v 1.1 2012/01/26 11:14:54 mwdavies Exp $

BUILDLINK_TREE+=	analitza

.if !defined(ANALITZA_BUILDLINK3_MK)
ANALITZA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.analitza+=	analitza>=4.8.0
BUILDLINK_PKGSRCDIR.analitza?=	../../wip/analitza

.include "../../wip/kdelibs4/buildlink3.mk"
.endif	# ANALITZA_BUILDLINK3_MK

BUILDLINK_TREE+=	-analitza
