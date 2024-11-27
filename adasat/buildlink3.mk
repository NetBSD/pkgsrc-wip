# $NetBSD: buildlink3.mk,v 1.0 2024/05/14 09:30:00 dkazankov Exp $

BUILDLINK_TREE+=	adasat

.if !defined(ADASAT_BUILDLINK3_MK)
ADASAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adasat+=	adasat>=24.0
BUILDLINK_PKGSRCDIR.adasat=	../../wip/adasat
BUILDLINK_DEPMETHOD.adasat?=	build

BUILDLINK_FILES.adasat=		include/adasat*/* lib/adasat*/*
BUILDLINK_FILES.adasat+=	share/gpr/manifests/adasat share/gpr/adasat.gpr

BUILDLINK_CONTENTS_FILTER.adasat=	\
	${EGREP} '(include/.*\.ads$$|lib/.*\.ali$$|lib/.*\.a$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$)'

.endif

BUILDLINK_TREE+=	-adasat
