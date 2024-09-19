# $NetBSD$

DISTNAME=	sipvicious-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sipvicious/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.sipvicious.org/
COMMENT=	Set of tools that can be used to audit SIP based VoIP systems
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in svcrack svcrash svmap svreport svwar
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sipvicious_${bin} sipvicious_${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
