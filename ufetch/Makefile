# $NetBSD$

DISTNAME=	ufetch-v0.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/jschx/ufetch/-/archive/v0.1/

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://gitlab.com/jschx/ufetch/-/archive/v0.1/
COMMENT=	Tiny system info for Unix-like operating systems
LICENSE=	isc

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

NO_BUILD=	yes

do-install:
	(cd ${WRKDIR}/${DISTNAME} && mv ufetch-netbsd ufetch && chmod +x ufetch && cp ufetch /usr/pkg/bin)

.include "../../mk/bsd.pkg.mk"
