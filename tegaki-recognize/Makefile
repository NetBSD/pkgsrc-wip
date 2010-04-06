# $NetBSD: Makefile,v 1.2 2010/04/06 11:44:54 obache Exp $
#

DISTNAME=	tegaki-recognize-0.3.1.2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.3.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project integration in the desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../wip/tegaki-pygtk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	bin/tegaki-recognize

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
