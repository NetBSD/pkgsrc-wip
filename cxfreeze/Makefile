# $NetBSD: Makefile,v 1.2 2010/08/11 17:27:26 helgoman Exp $
#

VERS=					4.2
DISTNAME=				cx_Freeze-${VERS}
CATEGORIES=				devel
MASTER_SITES=			${MASTER_SITE_SOURCEFORGE:=cx-freeze/}

MAINTAINER=				helgoman@users.sourceforge.net
HOMEPAGE=				http://cx-freeze.sourceforge.net/
COMMENT=				Freezing python scripts into executables
LICENSE=				python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_DEVELOPER=			yes


USE_LANGUAGES=      	c c++

PYDISTUTILSPKG=         yes


.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
