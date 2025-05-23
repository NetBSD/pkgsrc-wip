# $NetBSD: buildlink3.mk,v 1.0 2024/05/14 09:30:00 dkazankov Exp $

BUILDLINK_TREE+=	adasat

.if !defined(ADASAT_BUILDLINK3_MK)
ADASAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adasat+=	adasat>=24.0.0
BUILDLINK_ABI_DEPENDS.adasat+=	adasat>=25.0.0
BUILDLINK_PKGSRCDIR.adasat?=	../../wip/adasat
BUILDLINK_DEPMETHOD.adasat?=	build

BUILDLINK_CONTENTS_FILTER.adasat=	\
	${EGREP} '(include/.*\.ad.$$|lib/.*\.ali$$|lib/.*\.a$$|lib/.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$)'

pkgbase := adasat
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-adasat
