# $NetBSD: Makefile,v 1.6 2003/06/25 20:27:35 cubidou Exp $
.include "../../wip/gkrellm2/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-server
COMMENT=		monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../wip/gkrellm2-share

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
PTHREAD_OPTS=		require
RCD_SCRIPTS=		gkrellmd
CONF_FILES=		${PREFIX}/share/examples/gkrellm-server/gkrellmd.conf ${PREFIX}/etc/gkrellmd.conf

SPECIAL_PERMS+=         ${PREFIX}/bin/gkrellmd ${ROOT_USER} kmem 2711

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

WRKSRC=			${GKRELLM_SRCDIR}

pre-build:
	${SED} -e s,@@PREFIX@@,${PREFIX}, \
	    <${WRKSRC}/server/gkrellmd.h >${WRKSRC}/server/gkrellmd.h.sed
	${MV} ${WRKSRC}/server/gkrellmd.h.sed ${WRKSRC}/server/gkrellmd.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gkrellm-server
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf ${PREFIX}/share/examples/gkrellm-server

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
