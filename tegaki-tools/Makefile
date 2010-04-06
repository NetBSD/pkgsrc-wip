# $NetBSD: Makefile,v 1.2 2010/04/06 11:44:54 obache Exp $
#

DISTNAME=	tegaki-tools-0.3.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

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
