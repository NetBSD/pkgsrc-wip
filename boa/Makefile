DISTNAME=	boa-0.94.13
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=boa/}

HOMEPAGE=	http://www.boa.org/
COMMENT=	a small HTTP server
MAINTAINER=	schwarz@netbsd.org

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/boa
EGDIR=		${PREFIX}/share/examples/boa
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make lex
WRKSRC=		${WRKDIR}/${DISTNAME}/src	

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6
.if defined (USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CPPFLAGS+=	-DINET6
.endif

INSTALLATION_DIRS=	sbin man/man8

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/boa ${WRKSRC}/boa_indexer ${PREFIX}/sbin
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/boa.conf ${EGDIR}
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/boa
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/CREDITS ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/boa
		${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/boa.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
