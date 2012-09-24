# $NetBSD: Makefile,v 1.3 2012/09/24 17:59:15 asau Exp $
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


USE_LANGUAGES=      	c c++

PYDISTUTILSPKG=         yes


.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
