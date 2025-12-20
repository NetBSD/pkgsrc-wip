# $NetBSD: $
#
# This mk fragment can be included in all packages that uses `scdoc'
# as a tool.
#
# Keywords: man
#

.if !defined(SCDOC_TOOL_MK)
SCDOC_TOOL_MK=	defined

BUILDLINK_TARGETS+=	buildlink-bin-scdoc buildlink-pkgconfig-scdoc

.PHONY: buildlink-bin-scdoc
buildlink-bin-scdoc:
	${RUN} \
	f="${PREFIX}/bin/scdoc"; \
	t="${BUILDLINK_DIR}/bin/scdoc"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi

.PHONY: buildlink-pkgconfig-scdoc
buildlink-pkgconfig-scdoc:
	${RUN} \
	f="${PREFIX}/share/pkgconfig/scdoc.pc"; \
	t="${BUILDLINK_DIR}/share/pkgconfig/scdoc.pc"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi

.endif # SCDOC_TOOL_MK
