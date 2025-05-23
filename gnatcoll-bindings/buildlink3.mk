# $NetBSD: buildlink3.mk,v 1.0 2024/05/14 09:30:00 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-bindings

.if !defined(GNATCOLL_BINDINGS_BUILDLINK3_MK)
GNATCOLL_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-bindings+=	gnatcoll-bindings>=24.0.0
BUILDLINK_ABI_DEPENDS.gnatcoll-bindings+=	gnatcoll-bindings>=25.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-bindings?=		../../wip/gnatcoll-bindings
BUILDLINK_DEPMETHOD.gnatcoll-bindings?=		build

BUILDLINK_CONTENTS_FILTER.gnatcoll-bindings=	\
	${EGREP} '(include/.*\.ad.$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libgnatcoll.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr)'

pkgbase := gnatcoll-bindings
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-gnatcoll-bindings
