# $NetBSD: buildlink3.mk,v 1.1 2011/11/18 06:06:57 phonohawk Exp $

BUILDLINK_TREE+=	cedet

.if !defined(CEDET_BUILDLINK3_MK)
CEDET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cedet+=	${EMACS_PKGNAME_PREFIX}cedet>=1.0
BUILDLINK_PKGSRCDIR.cedet?=	../../wip/cedet

BUILDLINK_CONTENTS_FILTER.cedet=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif	# CEDET_BUILDLINK3_MK

BUILDLINK_TREE+=	-cedet
