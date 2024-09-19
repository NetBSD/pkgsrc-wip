# $NetBSD$

GITHUB_PROJECT=	dnspython-clientsubnetoption
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT:S/python-/-/}-2.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=opendns/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	be8ed04cf208f46eea542504f444982ab6fb4bc1 # master of 2016-04-06
# which is known as 2.1.0

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/opendns/dnspython-clientsubnetoption
COMMENT=	EDNS Client Subnet support for python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
EGG_NAME=	clientsubnetoption-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
