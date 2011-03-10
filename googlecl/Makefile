# $NetBSD: Makefile,v 1.1.1.1 2011/03/10 13:35:51 ryo-on Exp $
#

DISTNAME=	googlecl-0.9.12
CATEGORIES=	net
MASTER_SITES=	http://googlecl.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/googlecl/
COMMENT=	Command line tools for the Google Data APIs
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/google.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../www/py-gdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
