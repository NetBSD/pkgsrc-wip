# $NetBSD$

GITHUB_PROJECT=	s3transfer
DISTNAME=	${GITHUB_PROJECT}-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=boto/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/boto/s3transfer/
COMMENT=	Amazon S3 Transfer Manager for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jmespath>=1.3.0:../../wip/py-botocore

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
