# $NetBSD: Makefile,v 1.9 2012/07/24 19:44:55 bubuchka Exp $
#

DISTNAME=	ipaddr-2.1.10
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
