# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:33 asau Exp $
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

DEPENDS+=       		${PYPKGPREFIX}-xlrd>=0.7.1:../../textproc/py-xlrd

.include "../../lang/python/egg.mk"
.include "../../wip/py-errorhandler/buildlink3.mk"
.include "../../wip/py-xlwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
