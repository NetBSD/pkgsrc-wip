# $NetBSD: Makefile,v 1.2 2009/05/24 09:26:15 jihbed Exp $
#

DISTNAME=	foolscap-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://foolscap.lothar.com/releases/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://foolscap.lothar.com/trac
COMMENT=	Foolscap contains an RPC protocol for Twisted
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL


PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED= 26 25 24

REPLACE_PYTHON+=	bin/flogtool

INSTALLATION_DIRS=	share/doc


.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
