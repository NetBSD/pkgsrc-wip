# $NetBSD: buildlink3.mk,v 1.2 2011/11/21 19:08:57 absd Exp $

BUILDLINK_TREE+=	tcl86

.if !defined(TCL86_BUILDLINK3_MK)
TCL86_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl86+=	tcl86>=8.6
BUILDLINK_ABI_DEPENDS.tcl86+=	tcl86>=8.6
BUILDLINK_PKGSRCDIR.tcl86?=	../../wip/tcl86

BUILDLINK_FILES.tcl86+=	bin/tclsh*
#
# Make "-ltcl" and "-ltcl86" resolve into "-ltcl8.6", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl8.6
BUILDLINK_TRANSFORM+=	l:tcl86:tcl8.6

TCLCONFIG_SH_DIR?=	${BUILDLINK_PREFIX.tcl86}/lib/
TCLCONFIG_SH?=		${TCLCONFIG_SH_DIR}/tclConfig.sh

.endif # TCL86_BUILDLINK3_MK

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TREE+=	-tcl86
