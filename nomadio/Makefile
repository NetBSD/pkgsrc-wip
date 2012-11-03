# $NetBSD: Makefile,v 1.7 2012/11/03 17:01:16 othyro Exp $

PKGVERSION=		0.7
DISTNAME=		nomadio-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.lucifier.net/pub/nomadio/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://nomadio.lucifier.net/
COMMENT=		Utility to control Creative Nomad II MG

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

WRKSRC=			${WRKDIR}/${DISTNAME:S/-${PKGVERSION_NOREV}//}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomadio ${DESTDIR}${PREFIX}/bin/nomadio
	${INSTALL_MAN} ${WRKSRC}/nomadio.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nomadio.1

.include "../../mk/bsd.pkg.mk"
