# $NetBSD$

DISTNAME=       dnspython-clientsubnetoption-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_GITHUB:=opendns/}
GITHUB_PROJECT=	dnspython-clientsubnetoption
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE= 	https://github.com/opendns/dnspython-clientsubnetoption
COMMENT=	EDNS Client Subnet support for python
LICENSE=	modified-bsd
# note the LICENSE document is missing part of final sentence
# I reported this to them.

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
