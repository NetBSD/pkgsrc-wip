# $NetBSD: Makefile,v 1.3 2003/04/06 05:00:31 cubidou Exp $

PKGNAME=	gkrellm-share-2.1.8a
.include "../../wip/gkrellm2/Makefile.common"

COMMENT=	gkrellm2 shared files
CONFLICTS=	gkrellm-1*

BUILD_USES_MSGFMT=	YES

WRKSRC=			${WRKDIR}/gkrellm-2.1.8/po

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
