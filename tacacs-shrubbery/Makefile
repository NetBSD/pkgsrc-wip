# $NetBSD: Makefile,v 1.6 2006/09/16 19:04:11 gschwarz Exp $
#

DISTNAME=	tacacs+-F4.0.4.13
PKGNAME=	${DISTNAME:S,tacacs+,tacacs,}
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.shrubbery.net/tac_plus/
COMMENT=	Cisco AAA protocol (tacacs+) daemon (Shrubbery Networks version)

.include "options.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl

CONFIGURE_ARGS+=	--with-acctfile=${VARBASE:Q}/log/tac_plus.acct
CONFIGURE_ARGS+=	--with-logfile=${VARBASE:Q}/log/tac_plus.log
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE:Q}/run/tac_plus.pid
CONFIGURE_ENV+=		PERLV_PATH=${PERL5:Q}

.include "../../mk/bsd.prefs.mk"

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=		-Duint16_t=u_int16_t -Duint32_t=u_int32_t \
			-Dsocklen_t=int
# need snprintf()
. include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 share/doc/tacacs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${WRKSRC}/tac_pwd \
	${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tac_convert ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/regexp.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/tac_plus.conf.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/tac_plus.8 ${WRKSRC}/tac_pwd.8 \
	${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tacacs

.include "../../mk/bsd.pkg.mk"
