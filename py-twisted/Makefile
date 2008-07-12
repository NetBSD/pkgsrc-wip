# $NetBSD: Makefile,v 1.23 2008/07/12 00:30:11 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
CATEGORIES =	meta-pkgs net python
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	Event-driven networking framework for Python

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-conch>=8.1.0:../../wip/py-twisted-conch
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=8.1.0:../../wip/py-twisted-web
DEPENDS+=	${PYPKGPREFIX}-twisted-lore>=8.1.0:../../wip/py-twisted-lore
DEPENDS+=	${PYPKGPREFIX}-twisted-names>=8.1.0:../../wip/py-twisted-names
DEPENDS+=	${PYPKGPREFIX}-twisted-mail>=8.1.0:../../wip/py-twisted-mail
DEPENDS+=	${PYPKGPREFIX}-twisted-runner>=8.0.0:../../wip/py-twisted-runner
DEPENDS+=	${PYPKGPREFIX}-twisted-words>=8.1.0:../../wip/py-twisted-words
DEPENDS+=	${PYPKGPREFIX}-twisted-news>=8.1.0:../../wip/py-twisted-news

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:     # empty

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
