# $NetBSD: Makefile,v 1.18 2012/09/24 17:14:36 asau Exp $
#

DISTNAME=	boa-0.94.14rc21
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.boa.org/
COMMENT=	Small HTTP server
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR=	boa
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-debug
EGDIR=			${PREFIX}/share/examples/boa
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex
USE_FEATURES+=		snprintf

.include "../../mk/bsd.prefs.mk"

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.boa
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif

CONF_FILES=		${EGDIR}/boa.conf ${PKG_SYSCONFDIR}/boa.conf
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/doc/boa share/examples/boa

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa_indexer ${DESTDIR}${PREFIX}/sbin/
.for f in boa.conf cgi-test.cgi nph-test.cgi resolver.pl
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}${EGDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/boa
	${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
