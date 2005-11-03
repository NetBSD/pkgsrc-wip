# $Id: Makefile,v 1.6 2005/11/03 13:12:10 rillig Exp $
#

DISTNAME=	boa-0.94.14rc21
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.boa.org/
COMMENT=	Small HTTP server

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa_indexer ${PREFIX}/sbin/
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in boa.conf cgi-test.cgi nph-test.cgi resolver.pl
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EGDIR}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/boa
	${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
