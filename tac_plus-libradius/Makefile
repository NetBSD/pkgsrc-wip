# $NetBSD: Makefile,v 1.9 2012/10/07 17:17:21 asau Exp $

DISTNAME=	tac_plus.F5.0.0.alpha-libradius
PKGNAME=	tac_plus-libradius-5.0.0
CATEGORIES=	net security
MASTER_SITES=	https://web.archive.org/web/20040613103123if_/http://portal-to-web.de:80/tacacs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20040613103123/http://portal-to-web.de/tacacs/
COMMENT=	Version of Cisco's tac_plus Tacacs server with RADIUS support

EXTRACT_CMD=	${TAR} xf $$extract_file

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

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-return-type
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
