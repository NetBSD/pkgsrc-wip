# $NetBSD: Makefile,v 1.2 2007/09/21 13:06:55 thomasklausner Exp $
#

DISTNAME=	python-gnucash-0.7.10
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	http://www.parit.ca/projects/pythongnucash/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.parit.ca/projects/pythongnucash/
COMMENT=	Python bindings to the GnuCash libraries

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=	include
SUBST_STAGE.include=	pre-configure
SUBST_SED.include+=	-e 's,/usr/include/glib,${PREFIX}/include/glib/glib,g'
SUBST_SED.include+=	-e 's,/usr/lib,${PREFIX}/lib,g'
SUBST_FILES.include+=	setup.py
SUBST_MESSAGE.include=	Fixing header search paths.

.include "../../finance/gnucash/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
