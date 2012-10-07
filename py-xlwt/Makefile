# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:33 asau Exp $
#

VERS=					0.7.2
DISTNAME=				xlwt-${VERS}
PKGNAME=				${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=				2
CATEGORIES=				textproc
MASTER_SITES=			http://pypi.python.org/packages/source/x/xlwt/

MAINTAINER=				helgoman@users.sourceforge.net
HOMEPAGE=				https://secure.simplistix.co.uk/svn/xlwt/trunk/
COMMENT=				Library to create spreadsheet files

LICENSE=				original-bsd

PYDISTUTILSPKG=			yes
PLIST_SUBST+=			EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
