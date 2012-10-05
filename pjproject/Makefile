# $NetBSD: Makefile,v 1.3 2012/10/05 11:21:46 asau Exp $

DISTNAME=	pjproject-0.5.10.3
CATEGORIES=	audio multimedia devel
MASTER_SITES=	http://www.pjsip.org/release/0.5.10.3/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://www.pjsip.org/
COMMENT=	Small footprint SIP stack

CONFIGURE_SCRIPT=	./aconfigure
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS=		gmake

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/*/lib/* ${DESTDIR}${PREFIX}/lib
	find ${WRKSRC}/*/bin -type f -exec ${INSTALL_PROGRAM} '{}' ${DESTDIR}${PREFIX}/bin \;

.include "../../mk/bsd.pkg.mk"
