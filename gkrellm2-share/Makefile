# $NetBSD: Makefile,v 1.6 2003/09/15 05:00:47 cubidou Exp $
.include "../../wip/gkrellm2/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files
CONFLICTS=		gkrellm-1*

BUILD_USES_MSGFMT=	YES

MAKE_ENV+=		MODULES=po

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
