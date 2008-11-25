#####################################################################
.if defined(DIST_SUBDIR) && !empty(DIST_SUBDIR)
_ALLSRCFILES=    ${DISTFILES:@f@${DIST_SUBDIR}/${f}@} \
                 ${PATCHFILES:@f@${DIST_SUBDIR}/${f}@}
.else
_ALLSRCFILES=     ${_DISTFILES} ${_PATCHFILES}
.endif

ALLSRCFILES=     ${_ALLSRCFILES:O:u}

#####################################################################
# for multi-variant packages and bulk build software
.for i in ${_PBULK_MULTI}
_MULTI_SPEC_VAR1.${_PBULK_MULTI_VAR.${i}}=${${_PBULK_MULTI_DEFAULT.${i}}}
_MULTI_SPEC_ACCEPTED.${_PBULK_MULTI_VAR.${i}}=${_PBULK_MULTI_LIST.${i}}
.if !empty(${_PBULK_MULTI_LIST.${i}})
VARIANTS7+=	${_PBULK_MULTI_VAR.${i}}=${${_PBULK_MULTI_LIST.${i}}:ts,}
.endif
.endfor

.for _SINGLE_ASSIGN in ${_ASSIGNMENTS:S/,/ /g}
_varname=	${_SINGLE_ASSIGN:C/=.*$//1}
_value=		${_SINGLE_ASSIGN:C/^[^=]*=//1}
.if !defined(_MULTI_SPEC_VAR1.${_varname}) || \
    "${_MULTI_SPEC_VAR1.${_varname}}" != "${_value}"
_ASSIGN2+=	${_SINGLE_ASSIGN}
.endif
.if defined(_MULTI_SPEC_VAR1.${_varname})
_INHER_ASSIGNS+=	${_SINGLE_ASSIGN}
.endif
.endfor

ASSIGNMENTS=	${_ASSIGN2:ts,}
INHER_ASSIGNS=	${_INHER_ASSIGNS:ts,}

#####################################################################
.PHONY: my-show-vars
my-show-vars:
.for VARNAME in ${VARNAMES}
.if !empty(${VARNAME})
	@${ECHO} ${VARNAME}=${${VARNAME}:Q}
.endif
.endfor
