# $NetBSD: buildlink3.mk,v 1.0 2024/05/06 18:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gprlib

.if !defined(GPRLIB_BUILDLINK3_MK)
GPRLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprlib+=	gprlib>=24.0.0
BUILDLINK_PKGSRCDIR.gprlib=	../../wip/gprlib
BUILDLINK_DEPMETHOD.gprlib?=	build

BUILDLINK_AUTO_VARS.gprlib=	no
BUILDLINK_AUTO_DIRS.gprlib=	no

BUILDLINK_FILES.gprlib=		lib/libgnatprj.so
BUILDLINK_FILES.gprlib=		include/gpr/* lib/libgnatprj* lib/gpr/*
BUILDLINK_FILES.gprlib+=	share/gpr/manifests/gpr share/gpr/gpr.gpr

BUILDLINK_CONTENTS_FILTER.gprlib=	\
	${EGREP} '(include/.*\.ads$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libgnatprj.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$|/gpr\.adb$$|/gpr-util-put_resource_usage__unix\.adb$$)'

.endif

BUILDLINK_TREE+=	-gprlib
