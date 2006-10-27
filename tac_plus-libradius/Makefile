# $NetBSD: Makefile,v 1.1.1.1 2006/10/27 21:39:28 gschwarz Exp $

DISTNAME=	tac_plus.F5.0.0.alpha-libradius
PKGNAME=	tac_plus-libradius-5.0.0
CATEGORIES=	net security
MASTER_SITES=	http://www.portal-to-web.de/tacacs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.portal-to-web.de/tacacs/
COMMENT=	Version of Cisco's tac_plus Tacacs server with RADIUS support

INSTALLATION_DIRS=	sbin man/man8 share/doc/tac_plus \
			share/examples/tac_plus ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"
#.include "options.mk"

GNU_CONFIGURE=	yes
#USE_TOOLS+=	perl
BUILD_TARGET=	tac_plus

.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DNO_PWAGE
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 \
	${PREFIX}/${PKGMANDIR}/man8/tac_plus.8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/tac_plus.cfg ${PREFIX}/share/examples/tac_plus

.include "../../mk/bsd.pkg.mk"
