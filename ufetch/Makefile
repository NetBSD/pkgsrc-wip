# $NetBSD$

DISTNAME=	ufetch-v0.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/jschx/ufetch/-/archive/v0.1/

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://gitlab.com/jschx/ufetch/-/archive/v0.1/
COMMENT=	Tiny system info for Unix-like operating systems
LICENSE=	isc

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	bin share/doc/ufetch

do-install:
	cd ${WRKSRC} && mv ufetch-netbsd ufetch && \
	${INSTALL_SCRIPT} ${WRKSRC}/ufetch ${DESTDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/LICENSE \
	${DESTDIR}${PREFIX}/share/doc/ufetch/LICENSE

.include "../../mk/bsd.pkg.mk"
