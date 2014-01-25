# $NetBSD: Makefile,v 1.4 2014/01/25 10:38:12 thomasklausner Exp $

DISTNAME=	googlecl-0.9.13
CATEGORIES=	net
MASTER_SITES=	http://googlecl.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/googlecl/
COMMENT=	Command line tools for the Google Data APIs
LICENSE=	apache-2.0

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gdata

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/google.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../www/py-gdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
