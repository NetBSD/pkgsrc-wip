# $NetBSD: buildlink3.mk,v 1.1 2025/03/05 06:28:49 scole Exp $

BUILDLINK_TREE+=	tcl90

.if !defined(TCL_BUILDLINK3_MK)
TCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl90+=	tcl90>=9.0.1
BUILDLINK_ABI_DEPENDS.tcl90+=	tcl90>=9.0.1
BUILDLINK_PKGSRCDIR.tcl90?=	../../wip/tcl90

BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/tcl/9.0
BUILDLINK_FILES.tcl90+=			tcl/9.0/bin/*
BUILDLINK_FNAME_TRANSFORM.tcl90+=	-e s,tcl/9.0/bin,bin,
BUILDLINK_FNAME_TRANSFORM.tcl90+=	-e s,tcl/9.0/lib/pkgconfig,lib/pkgconfig,

BUILDLINK_FILES.tcl90+=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl9.0", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl9.0

TCL90_SUBDIR=		tcl/9.0

_TOOLS_USE_PKGSRC.tclsh=	yes

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl90}/lib/tclConfig.sh
TCLSH=			${BUILDLINK_PREFIX.tcl90}/bin/tclsh
# Bundled library
ITCL_VERSION=		4.3.2
TDBC_VERSION=		1.1.10

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # TCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl90
