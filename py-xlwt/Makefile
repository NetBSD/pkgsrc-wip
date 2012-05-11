# $NetBSD: Makefile,v 1.3 2012/05/11 12:47:08 noud4 Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=			yes
PLIST_SUBST+=			EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
