# $NetBSD$

DISTNAME=	obnc-libstd_0.6.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	http://miasap.se/obnc/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://miasap.se/obnc/
LICENSE=	mpl-2.0

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c

DEPENDS+=	obnc-[0-9]*:../../wip/obnc

do-build:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		./build

do-install:
	cd ${WRKSRC} && \
	./install \
		--prefix=${PREFIX} \
		--destdir=${DESTDIR}

	# obnc also installs this same file, so remove to prevent conflicts
	rm -f ${DESTDIR}${PREFIX}/share/doc/obnc/obncdoc/index.html

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../wip/obnc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
