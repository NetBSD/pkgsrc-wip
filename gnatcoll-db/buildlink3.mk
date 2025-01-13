# $NetBSD: buildlink3.mk,v 1.0 2024/05/14 09:30:00 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-db

.if !defined(GNATCOLL_DB_BUILDLINK3_MK)
GNATCOLL_DB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-db+=	gnatcoll-db>=24.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-db=	../../wip/gnatcoll-db
BUILDLINK_DEPMETHOD.gnatcoll-db?=	build

BUILDLINK_FILES.gnatcoll-db=	include/gnatcoll_*/* lib/libgnatcoll* lib/gnatcoll_*/*
BUILDLINK_FILES.gnatcoll-db+=	share/gpr/manifests/gnatcoll_* share/gpr/gnatcoll_*.gpr
BUILDLINK_FILES.gnatcoll-db+=	bin/gnatcoll_*2ada bin/gnatinspect

BUILDLINK_CONTENTS_FILTER.gnatcoll-db=	\
	${EGREP} '(include/.*\.ads$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libgnatcoll.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$|bin/gnatcoll_.*2ada$$|bin/gnatinspect$$)'

pkgbase := gnatcoll-db
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gnatcoll-db
