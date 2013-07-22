# $NetBSD: Makefile,v 1.1 2013/07/22 17:01:46 shattered Exp $
#

DISTNAME=	macro11-2013.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/shattered/macro11/archive/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	https://github.com/shattered/macro11/
COMMENT=	Portable replacement of MACRO-11 (PDP-11 assembler)
#LICENSE=	# TODO: (see mk/license.mk)

FETCH_USING=	curl
WRKSRC=		${WRKDIR}/macro11-${DISTNAME}
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin share/doc/macro11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macro11 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dumpobj ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/macro11

.include "../../mk/bsd.pkg.mk"
