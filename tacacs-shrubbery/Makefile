# $NetBSD: Makefile,v 1.14 2011/01/19 21:28:37 gschwarz Exp $
#

DISTNAME=	tacacs+-F4.0.4.19
PKGNAME=	${DISTNAME:S,-F,-,}
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.shrubbery.net/tac_plus/
COMMENT=	Cisco AAA protocol (tacacs+) daemon (Shrubbery Networks version)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	id # used in options.mk

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl
USE_FEATURES+=	snprintf

CONFIGURE_ARGS+=	--with-acctfile=${VARBASE:Q}/log/tac_plus.acct
CONFIGURE_ARGS+=	--with-logfile=${VARBASE:Q}/log/tac_plus.log
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE:Q}/run/tac_plus.pid
CONFIGURE_ENV+=		PERLV_PATH=${PERL5:Q}
BUILD_DEFS+=		VARBASE

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=		-Duint16_t=u_int16_t -Duint32_t=u_int32_t
.endif

.if exists(/usr/include/pam/pam_appl.h) # MacOS X prior to 10.6
CPPFLAGS+=		-DPAM-PAM
.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 share/doc/tacacs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${WRKSRC}/tac_pwd \
	${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tac_convert ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/regexp.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/tac_plus.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/tac_plus.8 ${WRKSRC}/tac_pwd.8 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${DESTDIR}${PREFIX}/share/doc/tacacs

.include "../../mk/bsd.pkg.mk"
