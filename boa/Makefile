DISTNAME=	boa-0.94.14rc21
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

HOMEPAGE=	http://www.boa.org/
COMMENT=	a small HTTP server
MAINTAINER=	schwarz@NetBSD.org

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/boa
EGDIR=		${PREFIX}/share/examples/boa
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake lex

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

BUILD_DEFS+=	USE_INET6
.if defined (USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CPPFLAGS+=	-DINET6
.endif

INSTALLATION_DIRS=	sbin man/man8

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/boa \
		${WRKSRC}/src/boa_indexer ${PREFIX}/sbin
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/examples/boa.conf \
		${WRKSRC}/examples/cgi-test.cgi \
		${WRKSRC}/examples/nph-test.cgi \
		${WRKSRC}/examples/resolver.pl ${EGDIR}
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/boa
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${WRKSRC}/README \
		${PREFIX}/share/doc/boa
		${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
