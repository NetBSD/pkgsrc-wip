# $NetBSD: Makefile,v 1.1.1.1 2009/05/23 20:46:10 jihbed Exp $
#

DISTNAME=	foolscap-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://foolscap.lothar.com/releases/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://foolscap.lothar.com/trac
COMMENT=	Foolscap contains an RPC protocol for Twisted
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

REPLACE_PYTHON+=	bin/flogtool

INSTALLATION_DIRS=	share/doc


.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
