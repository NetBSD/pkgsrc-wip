# $NetBSD: Makefile,v 1.8 2012/04/08 19:09:47 thomasklausner Exp $
#

DISTNAME=	ipaddr-2.1.7
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

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} ipaddr_test.py )

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
