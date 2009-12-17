# $NetBSD: Makefile,v 1.2 2009/12/17 18:16:09 bubuchka Exp $
#

DISTNAME=	ipaddr-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://ipaddr-py.googlecode.com/files/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://ipaddr-py.googlecode.com/
COMMENT=	IPv4/IPv6 address manipulation library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 26 25 24	# XXX - 30 also requires it

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
