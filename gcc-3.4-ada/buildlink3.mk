# $NetBSD: buildlink3.mk,v 1.16 2004/05/20 16:58:41 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCCADA_BUILDLINK3_MK:=  ${GCCADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gccAda-3.4.0:=${LOCALBASE}/gccAda-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gccAda
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:NgccAda}
BUILDLINK_PACKAGES+=    gccAda

.if !empty(GCCADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gccAda+=      gccAda>=3.4.0
BUILDLINK_PKGSRCDIR.gccAda?=    ../../wip/gcc-3.4-ada
BUILDLINK_ENV+= ADAC=${LOCALBASE}/gccAda-3.4.0/bin/gcc
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gccAda-3.4.0/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_RPATHDIRS.gccAda+=       ${LOCALBASE}/gccAda-3.4.0/lib
BUILDLINK_RPATHDIRS.gccAda+=       ${_GCC_ARCHDIR}/adalib
BUILDLINK_RPATHDIRS.gccAda+=       ${_GCC_ARCHDIR}
BUILDLINK_LDFLAGS.gccAda+=	-L${LOCALBASE}/gccAda-3.4.0/lib -Wl,-R${LOCALBASE}/gccAda-3.4.0/lib
BUILDLINK_LDFLAGS.gccAda+=	-L${_GCC_ARCHDIR} -Wl,-R${_GCC_ARCHDIR}
.  endif
.endif  # GCCADA_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gccAda?=     ../../wip/gcc-3.4-ada
BUILDLINK_CONTENTS_FILTER.gccAda= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$|ada.*path)'

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gccAda?=	full
.  else
BUILDLINK_DEPMETHOD.gccAda?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
