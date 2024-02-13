# $NetBSD: buildlink3.mk,v 1.0 2023/12/11 12:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gprbuild

.if !defined(GPRBUILD_BUILDLINK3_MK)
GPRBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild+=	gprbuild>=24
BUILDLINK_ABI_DEPENDS.gprbuild+=	gprbuild>=24.0.0
BUILDLINK_PKGSRCDIR.gprbuild=		../../wip/gprbuild
BUILDLINK_DEPMETHOD.gprbuild?=		build

BUILDLINK_FILES.gprbuild+=	bin/gpr* libexec/gprbuild/* share/gpr/* share/gprbuild/*

.endif

BUILDLINK_TREE+=	-gprbuild
