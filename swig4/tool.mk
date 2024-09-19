# $NetBSD$
#
# This mk fragment can be included in all packages that use `swig'
# as a tool
#
# Based on lang/python/tool.mk
#
# Feel free to add if there is something missing
#

.if !defined(SWIG_TOOL_MK)
SWIG_TOOL_MK=	defined

TOOL_DEPENDS+=	swig4-[0-9]*:../../wip/swig4

BUILDLINK_TARGETS+=	buildlink-bin-swig

.PHONY: buildlink-bin-swig
buildlink-bin-swig:
.for bin in swig swig2.0 swig3.0 swig4.0
	${RUN} \
	t=${BUILDLINK_DIR}/bin/${bin}; \
	if ${TEST} -f "${PREFIX}/bin/swig4.0" -a ! -f $$t; then \
		${LN} -sf "${PREFIX}/bin/swig4.0" $$t; \
	fi
.endfor

.endif # SWIG_TOOL_MK
