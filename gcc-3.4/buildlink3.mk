# $NetBSD: buildlink3.mk,v 1.15 2004/05/23 12:48:49 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC34_BUILDLINK3_MK:=  ${GCC34_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc-3.4.0:=${LOCALBASE}/gcc-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc}
BUILDLINK_PACKAGES+=    gcc

.if !empty(GCC34_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc+=      gcc-3.4.0
BUILDLINK_PKGSRCDIR.gcc?=    ../../wip/gcc-3.4
_GNAT1!=${LOCALBASE}/gcc-3.4.0/bin/gcc -print-prog-name=gnat1
.  if exists(${_GNAT1})
BUILDLINK_ENV+=	ADAC=${LOCALBASE}/gcc-3.4.0/bin/gcc
.  endif
BUILDLINK_RPATHDIRS.gcc+=	${LOCALBASE}/gcc-3.4.0/lib
BUILDLINK_LDFLAGS.gcc+=	-L${LOCALBASE}/gcc-3.4.0/lib -Wl,-R${LOCALBASE}/gcc-3.4.0/lib
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gcc-3.4.0/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_RPATHDIRS.gcc+=	${_GCC_ARCHDIR}
BUILDLINK_LDFLAGS.gcc+=	-L${_GCC_ARCHDIR} -Wl,-R${_GCC_ARCHDIR}
.  endif
.endif  # GCC34_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc?=     ../../wip/gcc-3.4
BUILDLINK_CONTENTS_FILTER.gcc= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$|ada.*path)'

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc?=	full
.  else
BUILDLINK_DEPMETHOD.gcc?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
