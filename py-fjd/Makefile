# $NetBSD: Makefile,v 1.1 2014/03/21 10:54:21 jihbed Exp $

DISTNAME=	fjd-0.1.42
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/f/fjd/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/nhoening/fjd/
COMMENT=	File-based job distribution for everyone
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/fjd/scripts/fjd-dispatcher  ${WRKSRC}/fjd/scripts/fjd-dispatcher${PYVERSSUFFIX}
	${MV} ${WRKSRC}/fjd/scripts/fjd-worker ${WRKSRC}/fjd/scripts/fjd-worker${PYVERSSUFFIX}
	${MV} ${WRKSRC}/fjd/scripts/fjd-recruiter ${WRKSRC}/fjd/scripts/fjd-recruiter${PYVERSSUFFIX}
	${MV} ${WRKSRC}/fjd/scripts/bgscreen ${WRKSRC}/fjd/scripts/bgscreen${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.12.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-screenutils>=0.0.1.5.4:../../wip/py-screenutils
.include "../../mk/bsd.pkg.mk"
