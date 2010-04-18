# $NetBSD: Makefile,v 1.3 2010/04/18 12:44:34 jihbed Exp $
#

DISTNAME=	ipaddr-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://ipaddr-py.googlecode.com/files/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://ipaddr-py.googlecode.com/
COMMENT=	IPv4/IPv6 address manipulation library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 26 25 24	# XXX - 30 also requires it

do-test:
	( cd ${WRKSRC && ${PYTHONBIN} ipadrr_test.py )

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
