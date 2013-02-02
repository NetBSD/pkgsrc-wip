# $NetBSD: Makefile,v 1.4 2013/02/02 13:20:15 shattered Exp $
#

DISTNAME=		pypod-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://superduper.net/downloads/pypod/

DEPENDS+=		${PYPKGPREFIX}-mad>=0.5.0:../../audio/py-mad

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://superduper.net/index.py?page=pypod
COMMENT=		Python tools for manipluating iPod data
LICENSE=		gnu-gpl-v2

PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	*.py */*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
