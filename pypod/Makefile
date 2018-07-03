# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=		pypod-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://superduper.net/downloads/pypod/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://superduper.net/index.py?page=pypod
COMMENT=		Python tools for manipluating iPod data
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses
DEPENDS+=		${PYPKGPREFIX}-mad>=0.5.0:../../audio/py-mad

PYDISTUTILSPKG=		yes
REPLACE_PYTHON=		*.py */*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mad

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
