# $NetBSD$

DISTNAME=	obnc-libstd_0.6.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	lang
MASTER_SITES=	http://miasap.se/obnc/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miasap.se/obnc/
COMMENT=	Standard libraries for the OBNC compiler suite
# FIXME: gnu-gpl-v3 is the WRONG LICENSE. The real license is ``Mozilla Public License Version 2.0``.
#        See TODO on the rationale.
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c

do-build:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		./build

# Unlike obnc which uses ``./install --destdir=DESTDIR``, obnc-libstd
# uses ``./install DESTDIR`` instead.
# do-install:
# 	cd ${WRKSRC} && \
# 		./install ${DESTDIR}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../wip/obnc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
