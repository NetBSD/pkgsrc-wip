# $NetBSD: Makefile,v 1.1.1.1 2010/08/31 19:52:24 helgoman Exp $
#

VERS=					1.4.1
DISTNAME=				xlutils-${VERS}
PKGNAME=				${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=				textproc
MASTER_SITES=			http://pypi.python.org/packages/source/x/xlutils/

MAINTAINER=				helgoman@users.sourceforge.net
HOMEPAGE=				http://www.simplistix.co.uk/software/python/xlutils
COMMENT=				Utilities for working with Excel files
LICENSE=				mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=       		${PYPKGPREFIX}-xlrd>=0.7.1:../../textproc/py-xlrd

.include "../../lang/python/egg.mk"
.include "../../wip/py-errorhandler/buildlink3.mk"
.include "../../wip/py-xlwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
