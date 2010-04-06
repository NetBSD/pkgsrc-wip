# $NetBSD: Makefile,v 1.2 2010/04/06 11:44:55 obache Exp $
#

DISTNAME=	tegaki-train-0.3.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Train Tegaki with your own handwriting
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../wip/tegaki-pygtk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
