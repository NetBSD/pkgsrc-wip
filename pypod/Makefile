# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:53 thomasklausner Exp $
#

DISTNAME=		pypod-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://superduper.net/downloads/pypod/

DEPENDS+=		${PYPKGPREFIX}-mad>=0.5.0:../../audio/py-mad

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://superduper.net/index.py?page=pypod
COMMENT=		Python tools for manipluating iPod data

PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	*.py */*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
