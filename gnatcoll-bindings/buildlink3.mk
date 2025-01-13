# $NetBSD: buildlink3.mk,v 1.0 2024/05/14 09:30:00 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-bindings

.if !defined(GNATCOLL_BINDINGS_BUILDLINK3_MK)
GNATCOLL_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-bindings+=	gnatcoll-bindings>=24.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-bindings=		../../wip/gnatcoll-bindings
BUILDLINK_DEPMETHOD.gnatcoll-bindings?=		build

BUILDLINK_FILES.gnatcoll-bindings=	include/gnatcoll_*/* lib/libgnatcoll* lib/gnatcoll_*/*
BUILDLINK_FILES.gnatcoll-bindings+=	share/gpr/manifests/gnatcoll_* share/gpr/gnatcoll_*.gpr

BUILDLINK_CONTENTS_FILTER.gnatcoll-bindings=	\
	${EGREP} '(include/.*\.ads$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libgnatcoll.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr)'

.endif

BUILDLINK_TREE+=	-gnatcoll-bindings
