# $NetBSD: Makefile,v 1.1.1.1 2010/03/13 13:18:23 helgoman Exp $
#

DISTNAME=				cx_Freeze-4.1.2
PKGREVISION=			1
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
