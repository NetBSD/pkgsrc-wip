# $NetBSD: Makefile,v 1.8 2012/11/24 17:38:12 kristerw Exp $

DISTNAME=		nomadio-0.7
PKGREVISION=		1
CATEGORIES=		audio
#MASTER_SITES=		ftp://ftp.lucifier.net/pub/nomadio/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://nomadio.lucifier.net/
COMMENT=		Utility to control Creative Nomad II MG

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

WRKSRC=			${WRKDIR}/${DISTNAME:S/-${PKGVERSION_NOREV}//}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomadio ${DESTDIR}${PREFIX}/bin/nomadio
	${INSTALL_MAN} ${WRKSRC}/nomadio.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nomadio.1

.include "../../mk/bsd.pkg.mk"
