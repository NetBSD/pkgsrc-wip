# $NetBSD: Makefile,v 1.20 2006/08/27 16:50:05 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=        ${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
CATEGORIES =	meta-pkgs net python
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	Event-driven networking framework for Python

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-conch>=0.7.0:../../wip/py-twisted-conch
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.6.0:../../wip/py-twisted-web
DEPENDS+=	${PYPKGPREFIX}-twisted-lore>=0.2.0:../../wip/py-twisted-lore
DEPENDS+=	${PYPKGPREFIX}-twisted-names>=0.3.0:../../wip/py-twisted-names
DEPENDS+=	${PYPKGPREFIX}-twisted-mail>=0.3.0:../../wip/py-twisted-mail
DEPENDS+=	${PYPKGPREFIX}-twisted-runner>=0.2.0:../../wip/py-twisted-runner
DEPENDS+=	${PYPKGPREFIX}-twisted-words>=0.4.0:../../wip/py-twisted-words
DEPENDS+=	${PYPKGPREFIX}-twisted-news>=0.2.0:../../wip/py-twisted-news

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:     # empty

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
