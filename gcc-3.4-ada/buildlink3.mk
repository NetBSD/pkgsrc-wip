# $NetBSD: buildlink3.mk,v 1.21 2004/06/06 10:17:25 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCCADA_BUILDLINK3_MK:=  ${GCCADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc3-ada:=${LOCALBASE}/gcc3-ada-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc3-ada
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc3-ada}
BUILDLINK_PACKAGES+=    gcc3-ada

.if !empty(GCCADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc3-ada+=      gcc3-ada>=3.4.0
BUILDLINK_PKGSRCDIR.gcc3-ada?=    ../../lang/gcc3-ada
BUILDLINK_ENV+= ADAC=${BUILDLINK_PREFIX.gcc3-ada}/bin/gcc
_GCC_ARCHDIR!=	${DIRNAME} `${BUILDLINK_PREFIX.gcc3-ada}/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc3-ada+=       lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}
BUILDLINK_LIBDIRS.gcc3-ada+=       ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}/adalib
BUILDLINK_INCDIRS.gcc3-ada+=       include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}/adainclude
.  endif
.endif  # GCCADA_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc3-ada?=     ../../lang/gcc3-ada
BUILDLINK_FILES_CMD.gcc3-ada=	(cd  ${BUILDLINK_PREFIX.gcc3-ada} && \
	${FIND} bin libexec lib \( -type file -o -type link \) -print)
BUILDLINK_TRANSFORM.gcc3-ada=	-e s:\buildlink:buildlink/gcc3-ada-3.4.0:

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-ada?=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-ada?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
