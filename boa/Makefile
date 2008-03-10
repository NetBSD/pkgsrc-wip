# $NetBSD: Makefile,v 1.13 2008/03/10 20:50:24 asau Exp $
#

DISTNAME=	boa-0.94.14rc21
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.boa.org/
COMMENT=	Small HTTP server

PKG_SYSCONFSUBDIR=	boa
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-debug
EGDIR=		${PREFIX}/share/examples/boa
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake lex

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
# needs snprintf()
. include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

PKG_SUPPORTED_OPTIONS=	inet6
PKG_OPTIONS_VAR=	PKG_OPTIONS.boa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif

CONF_FILES=		${EGDIR}/boa.conf ${PKG_SYSCONFDIR}/boa.conf
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa ${DESDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa_indexer ${DESDIR}${PREFIX}/sbin/
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
.for f in boa.conf cgi-test.cgi nph-test.cgi resolver.pl
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}${EGDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESDIR}${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESDIR}${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/README ${DESDIR}${PREFIX}/share/doc/boa
	${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${DESDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
