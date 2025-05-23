# $NetBSD: buildlink3.mk,v 1.0 2024/05/06 18:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gprlib

.if !defined(GPRLIB_BUILDLINK3_MK)
GPRLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprlib+=	gprlib>=24.0.0
BUILDLINK_ABI_DEPENDS.gprlib+=	gprlib>=25.0.0
BUILDLINK_PKGSRCDIR.gprlib?=	../../wip/gprlib
BUILDLINK_DEPMETHOD.gprlib?=	build

BUILDLINK_CONTENTS_FILTER.gprlib=	\
	${EGREP} '(include/.*\.ad.$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libgnatprj.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$|/gpr\.adb$$|/gpr-util-put_resource_usage__unix\.adb$$)'

pkgbase := gprlib
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-gprlib
