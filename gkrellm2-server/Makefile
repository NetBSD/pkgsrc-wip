# $NetBSD: Makefile,v 1.2 2003/04/04 14:20:45 cubidou Exp $

PKGNAME=	gkrellm-server-2.1.8a
.include "../../wip/gkrellm2/Makefile.common"

DEPENDS+=		gkrellm-share-2.1.8a:../../wip/gkrellm2-share

USE_BUILDLINK2=		YES
PTHREAD_OPTS=		require
USE_PKGINSTALL=		YES
RCD_SCRIPTS=		gkrellmd
CONF_FILES=		${WRKSRC}/server/gkrellmd.conf ${PREFIX}/etc/gkrellmd.conf

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

WRKSRC=			${WRKDIR}/gkrellm-2.1.8

pre-build:
	${SED} -e s,@@PREFIX@@,${PREFIX}, \
	    <${WRKSRC}/server/gkrellmd.h >${WRKSRC}/server/gkrellmd.h.sed
	${MV} ${WRKSRC}/server/gkrellmd.h.sed ${WRKSRC}/server/gkrellmd.h

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
