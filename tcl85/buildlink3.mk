# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/07/24 19:29:36 egavilan Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TCL_BUILDLINK3_MK:=	${TCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl}
BUILDLINK_PACKAGES+=	tcl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tcl

.if !empty(TCL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.5.3
BUILDLINK_ABI_DEPENDS.tcl+=	tcl>=8.5.3
BUILDLINK_PKGSRCDIR.tcl?=	../../wip/tcl85

BUILDLINK_FILES.tcl+=	bin/tclsh*
#
# Make "-ltcl" and "-ltcl85" resolve into "-ltcl8.5", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl8.5
BUILDLINK_TRANSFORM+=	l:tcl85:tcl8.5

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tcl8.5/tclConfig.sh

PRINT_PLIST_AWK+=	/^@dirrm lib\/tcl$$/ \
				{ print "@comment in tcl: " $$0; next; }
.endif	# TCL_BUILDLINK3_MK

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
