# $NetBSD: Makefile,v 1.4 2003/04/07 17:54:32 cubidou Exp $
.include "../../wip/gkrellm2/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-share
WRKSRC=			${WRKDIR}/gkrellm-${GKRELLM_VERSION}/po

COMMENT=	gkrellm2 locale files
CONFLICTS=	gkrellm-1*

BUILD_USES_MSGFMT=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
