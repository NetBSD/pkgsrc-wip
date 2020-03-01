# $NetBSD$

DISTNAME=	actor-framework-0.17.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=actor-framework/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.actor-framework.org
COMMENT=	An Open Source Implementation of the Actor Model in C++
LICENSE=	boost-license

USE_CMAKE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

# ./configure is a wrapper around cmake, and doesn't seem to honor PREFIX env variable.
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} && \
		./configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} && \
		gmake DESTDIR=${DESTDIR} PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC}/build && ${SETENV} ${INSTALL_ENV} && \
		gmake DESTDIR=${DESTDIR} PREFIX=${PREFIX} install

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
