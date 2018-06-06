# $NetBSD$

DISTNAME=	obnc_0.12.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	lang
MASTER_SITES=	http://miasap.se/obnc/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miasap.se/obnc/
COMMENT=	a compiler for the Oberon programming language
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGE=	c

do-build:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		./build \
			--prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && \
		./install \
			--destdir=${DESTDIR}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
