# $NetBSD: Makefile,v 1.2 2007/05/11 12:41:07 lkundrak Exp $

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

do-install:
	${INSTALL_LIB} ${WRKSRC}/*/lib/* ${PREFIX}/lib
	find ${WRKSRC}/*/bin -type f -exec ${INSTALL_PROGRAM} '{}' ${PREFIX}/bin \;

.include "../../mk/bsd.pkg.mk"
