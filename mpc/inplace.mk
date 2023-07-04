# $NetBSD: inplace.mk,v 1.5 2015/09/15 20:56:33 joerg Exp $
#
# Include this file to extract math/mpc source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies math/mpc has.

.PHONY: fetch-inplace-mpc extract-inplace-mpc
post-fetch: fetch-inplace-mpc

post-extract: extract-inplace-mpc

fetch-inplace-mpc:
	(cd ../../math/mpc && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpc EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES checksum)

extract-inplace-mpc:
	(cd ../../math/mpc && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpc EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES patch)
	${MV} ${WRKSRC}/mpc-* ${WRKSRC}/mpc
