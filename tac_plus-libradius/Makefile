# $NetBSD: Makefile,v 1.3 2006/12/17 21:39:00 gschwarz Exp $

DISTNAME=	tac_plus.F5.0.0.alpha-libradius
PKGNAME=	tac_plus-libradius-5.0.0
CATEGORIES=	net security
MASTER_SITES=	http://www.portal-to-web.de/tacacs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.portal-to-web.de/tacacs/
COMMENT=	Version of Cisco's tac_plus Tacacs server with RADIUS support

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man8 share/doc/tac_plus \
			share/examples/tac_plus

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GNU_CONFIGURE=	yes
#USE_TOOLS+=	perl
BUILD_TARGET=	tac_plus

.if ${OPSYS} == "Darwin" || ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
CPPFLAGS+=	-DNO_PWAGE
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/generate_passwd \
	${PREFIX}/bin/tac_plus_generate_passwd
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 \
	${PREFIX}/${PKGMANDIR}/man8/tac_plus.8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/tac_plus.cfg ${PREFIX}/share/examples/tac_plus

.include "../../mk/bsd.pkg.mk"
