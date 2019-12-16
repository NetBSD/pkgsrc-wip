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
USE_TOOLS+=	pax
NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	cd ${WRKSRC} && mv ufetch-netbsd ufetch && \
	${PAX} -rw ufetch ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
