# $NetBSD: Makefile,v 1.8 2010/09/05 16:27:36 gschwarz Exp $

DISTNAME=	tac_plus.F5.0.0.alpha-libradius
PKGNAME=	tac_plus-libradius-5.0.0
CATEGORIES=	net security
MASTER_SITES=	http://www.portal-to-web.de/tacacs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.portal-to-web.de/tacacs/
COMMENT=	Version of Cisco's tac_plus Tacacs server with RADIUS support

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man8 share/doc/tac_plus \
			share/examples/tac_plus

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GNU_CONFIGURE=	yes
BUILD_TARGET=	tac_plus

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
CPPFLAGS+=	-DFREEBSD
.elif ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
CPPFLAGS+=	-DNETBSD
.elif ${OPSYS} == "IRIX"
CPPFLAGS+=	-DMIPS
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-9.*) || !empty(MACHINE_PLATFORM:MDarwin-1[0-9].*) # MacOS 10.5 or higher
CPPFLAGS+=	-DMACOSX5PLUS
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/generate_passwd \
	${DESTDIR}${PREFIX}/bin/tac_plus_generate_passwd
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/tac_plus.8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${DESTDIR}${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/tac_plus.cfg ${DESTDIR}${PREFIX}/share/examples/tac_plus

.include "../../mk/bsd.pkg.mk"
