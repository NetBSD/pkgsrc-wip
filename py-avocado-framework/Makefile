# $NetBSD$

DISTNAME=       avocado-framework-85.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     devel
MASTER_SITES=   ${MASTER_SITE_PYPI:=a/avocado-framework/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/avocado-framework/avocado/
COMMENT=	Next generation testing framework
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/avocado-framework

AVOCADO_BINARIES=	avocado \
			avocado-runner \
			avocado-runner-avocado-instrumented \
			avocado-runner-exec \
			avocado-runner-exec-test \
			avocado-runner-noop \
			avocado-runner-python-unittest \
			avocado-runner-tap \
			avocado-software-manager \

post-install:
	cd ${DESTDIR}${PREFIX}/bin && for b in ${AVOCADO_BINARIES}; \
	  do ${MV} $$b $$b-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
