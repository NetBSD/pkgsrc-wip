# $NetBSD: buildlink3.mk,v 1.1 2025/03/05 06:28:49 scole Exp $

BUILDLINK_TREE+=	tcl

.if !defined(TCL_BUILDLINK3_MK)
TCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl+=	tcl>=9.0.1
BUILDLINK_ABI_DEPENDS.tcl+=	tcl>=9.0.1
# xxx
#BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl
BUILDLINK_PKGSRCDIR.tcl?=	../../wip/tcl90

BUILDLINK_FILES.tcl+=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl9.0", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl9.0
#BUILDLINK_TRANSFORM+=	l:tcl90:tcl9.0

_TOOLS_USE_PKGSRC.tclsh=	yes

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
# Bundled library
ITCL_VERSION=		4.3.2
TDBC_VERSION=		1.1.10

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # TCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl
