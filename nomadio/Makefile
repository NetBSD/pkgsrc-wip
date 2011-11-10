# $NetBSD: Makefile,v 1.5 2011/11/10 01:03:44 othyro Exp $

PKGVERSION=		0.7
DISTNAME=		nomadio-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.lucifier.net/pub/nomadio/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://nomadio.lucifier.net/
COMMENT=		Utility to control Creative Nomad II MG
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

WRKSRC=			${WRKDIR}/${DISTNAME:S/-${PKGVERSION_NOREV}//}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomadio ${DESTDIR}${PREFIX}/bin/nomadio
	${INSTALL_MAN} ${WRKSRC}/nomadio.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nomadio.1
	${INSTALL_MAN} ${WRKSRC}/nomadio.cat1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/nomadio.0

.include "../../mk/bsd.pkg.mk"
