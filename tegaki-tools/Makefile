# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 10:30:45 obache Exp $
#

DISTNAME=	tegaki-tools-0.3
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.3/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Set of command-line tools for Tegaki
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.3:../../wip/tegaki-python
DEPENDS+=	tegaki-pygtk>=0.3:../../wip/tegaki-pygtk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
