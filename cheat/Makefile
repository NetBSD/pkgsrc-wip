# $NetBSD$

DISTNAME=	cheat-1.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tuplanolla/}
GITHUB_PROJECT=	cheat
GITHUB_TAG=	${PKGVERSION_NOREV}

OWNER=		micha@NetBSD.org
HOMEPAGE=	https://github.com/Tuplanolla/cheat/
COMMENT=	Convenient unit testing framework for the C programming language
LICENSE=	2-clause-bsd

USE_LANGUAGES=	#
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include man/man7

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} cheat.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC} && ${INSTALL_MAN} cheat.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7


.include "../../mk/bsd.pkg.mk"
