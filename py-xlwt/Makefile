# $NetBSD: Makefile,v 1.1.1.1 2010/08/31 19:51:17 helgoman Exp $
#

VERS=					0.7.2
DISTNAME=				xlwt-${VERS}
PKGNAME=				${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=				textproc
MASTER_SITES=			http://pypi.python.org/packages/source/x/xlwt/

MAINTAINER=				helgoman@users.sourceforge.net
HOMEPAGE=				https://secure.simplistix.co.uk/svn/xlwt/trunk/
COMMENT=				Library to create spreadsheet files

LICENSE=				original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=			yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
