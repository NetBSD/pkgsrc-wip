# $NetBSD: Makefile,v 1.2 2007/08/05 14:46:17 othyro Exp $

DISTNAME=		nomadio-0.7
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.lucifier.net/pub/nomadio/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://nomadio.lucifier.net/
COMMENT=		Utility to control Creative Nomad II MG

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomadio ${PREFIX}/bin/nomadio
	${INSTALL_MAN} ${WRKSRC}/nomadio.1 ${PREFIX}/${PKGMANDIR}/man1/nomadio.1
	${INSTALL_MAN} ${WRKSRC}/nomadio.cat1 ${PREFIX}/${PKGMANDIR}/cat1/nomadio.0

.include "../../mk/bsd.pkg.mk"
