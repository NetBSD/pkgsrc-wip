# $NetBSD$

.if !defined(IS_BUILTIN.libnsl)

BUILTIN_PKG:=	libnsl

BUILTIN_FIND_PKGCONFIG_FILES_VAR=	PC_LIBNSL
BUILTIN_FIND_PKGCONFIG_FILES.PC_LIBNSL=	libnsl.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###

IS_BUILTIN.libnsl=	no
.  if empty(PC_LIBNSL:M__nonexistent__)
IS_BUILTIN.libnsl=	yes
.  endif
.endif # IS_BUILTIN.libnsl
MAKEVARS+=		IS_BUILTIN.libnsl

###
### Determine whether we should use the built-in implementation.
###
.if !defined(USE_BUILTIN.libnsl)
.  if ${PREFER.libnsl} == "pkgsrc"
USE_BUILTIN.libnsl=	no
.  else
USE_BUILTIN.libnsl=	${IS_BUILTIN.libnsl}
.  endif  # PREFER.libnsl
.endif
MAKEVARS+=		USE_BUILTIN.libnsl

CHECK_BUILTIN?=	no
.if !empty(CHECK_BUILTIN.libnsl:M[nN][oO])
.  if !empty(USE_BUILTIN.libnsl:M[yY][eE][sS])
.    if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: link-libnsl-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig

.PHONY: link-libnsl-pkgconfig link-message-libnsl-pkgconfig
link-libnsl-pkgconfig: link-message-libnsl-pkgconfig
link-message-libnsl-pkgconfig:
	@${STEP_MSG} "Linking ${PC_LIBNSL} file into ${BUILDLINK_DIR}."

link-libnsl-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	${LN} -sf ${PC_LIBNSL} ${BLKDIR_PKGCFG}/${BUILTIN_FIND_PKGCONFIG_FILES.PC_LIBNSL}
.    endif
.  endif
.endif # CHECK_BUILTIN.libnsl
