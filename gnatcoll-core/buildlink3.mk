# $NetBSD: buildlink3.mk,v 1.0 2024/05/06 13:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-core

.if !defined(GNATCOLL_CORE_BUILDLINK3_MK)
GNATCOLL_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-core+=	gnatcoll-core>=24.0.0
BUILDLINK_ABI_DEPENDS.gnatcoll-core+=	gnatcoll-core>=25.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-core?=	../../wip/gnatcoll-core
BUILDLINK_DEPMETHOD.gnatcoll-core?=	build

BUILDLINK_CONTENTS_FILTER.gnatcoll-core=	\
	${EGREP} '(include/.*\.ads$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libgnatcoll.*$$|share/gpr/manifests/gnatcoll.*|share/gpr/gnatcoll.*\.gpr$$)'

pkgbase := gnatcoll-core
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-gnatcoll-core
