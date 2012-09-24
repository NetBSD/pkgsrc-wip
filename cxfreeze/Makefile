# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:56 asau Exp $
#

VERS=					4.2
DISTNAME=				cx_Freeze-${VERS}
CATEGORIES=				devel
MASTER_SITES=			${MASTER_SITE_SOURCEFORGE:=cx-freeze/}

MAINTAINER=				helgoman@users.sourceforge.net
HOMEPAGE=				http://cx-freeze.sourceforge.net/
COMMENT=				Freezing python scripts into executables
LICENSE=				python-software-foundation

USE_LANGUAGES=      	c c++

PYDISTUTILSPKG=         yes


.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
