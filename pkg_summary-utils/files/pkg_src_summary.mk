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
_VAR2DEFAULT.${_PBULK_MULTI_VAR.${i}}=${${_PBULK_MULTI_DEFAULT.${i}}}
_VAR2ACCEPTEDVARNAME.${_PBULK_MULTI_VAR.${i}}=${_PBULK_MULTI_LIST.${i}}
.endfor

.for _SINGLE_ASSIGN in ${_ASSIGNMENTS:S/,/ /g}
_varname=			${_SINGLE_ASSIGN:C/=.*$//1}
_value=				${_SINGLE_ASSIGN:C/^[^=]*=//1}
_VAR_ASSIGNED.${_varname}=	1
.if !defined(_VAR2DEFAULT.${_varname})
_ASSIGN2+=		${_SINGLE_ASSIGN}
.elif !defined(${_VAR2ACCEPTEDVARNAME.${_varname}})
__INHER_ASSIGNS_REJ+=	${_SINGLE_ASSIGN}
.elif "${_VAR2DEFAULT.${_varname}}" != "${_value}"
_ASSIGN2+=		${_SINGLE_ASSIGN}
__INHER_ASSIGNS+=	${_SINGLE_ASSIGN}
.else
__INHER_ASSIGNS_REJ+=	${_SINGLE_ASSIGN}
.endif
.endfor

ASSIGNMENTS=		${_ASSIGN2:ts,}
_INHER_ASSIGNS=		${__INHER_ASSIGNS:ts,}
_INHER_ASSIGNS_REJ=	${__INHER_ASSIGNS_REJ:ts,}

.for i in ${_PBULK_MULTI}
.if defined(${_PBULK_MULTI_LIST.${i}}) && !defined(_VAR_ASSIGNED.${_PBULK_MULTI_VAR.${i}})
_VARIANTS+=	${_PBULK_MULTI_VAR.${i}}=${${_PBULK_MULTI_LIST.${i}}:ts,}
.endif
.endfor

#####################################################################
.PHONY: my-show-vars
my-show-vars:
.for VARNAME in ${VARNAMES}
.if !empty(${VARNAME})
	@${ECHO} ${VARNAME}=${${VARNAME}:Q}
.endif
.endfor
