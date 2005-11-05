# $NetBSD: Makefile,v 1.7 2005/11/05 17:18:17 gschwarz Exp $
#

DISTNAME=	boa-0.94.14rc21
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.boa.org/
COMMENT=	Small HTTP server

PKG_SYSCONFSUBDIR=	boa
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
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

CONF_FILES=		${EGDIR}/boa.conf ${PKG_SYSCONFDIR}/boa.conf
USE_PKGINSTALL=YES
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

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
	${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
