# $NetBSD: Makefile,v 1.2 2003/04/04 14:20:46 cubidou Exp $

PKGNAME=	gkrellm-share-2.1.8a
.include "../../wip/gkrellm2/Makefile.common"

COMMENT=	gkrellm2 shared files

BUILD_USES_MSGFMT=	YES

WRKSRC=			${WRKDIR}/gkrellm-2.1.8/po

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
