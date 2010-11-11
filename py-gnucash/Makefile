# $NetBSD: Makefile,v 1.5 2010/11/11 22:42:07 shattered Exp $
#

DISTNAME=	python-gnucash-0.7.10
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	3
CATEGORIES=	finance
MASTER_SITES=	http://parit.ca/products/finance/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://parit.ca/products/finance/
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
