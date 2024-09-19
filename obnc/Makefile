# $NetBSD$

DISTNAME=	obnc_0.14.2
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	lang
MASTER_SITES=	http://miasap.se/obnc/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://miasap.se/obnc/
COMMENT=	Compiler for the Oberon programming language
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c

do-build:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		./build \
			--prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		./install \
			--destdir=${DESTDIR}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
