# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:20 thomasklausner Exp $
#

DISTNAME=	tegaki-pygtk-0.3.1
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Base user interface library for the Tegaki project
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.2:../../wip/tegaki-python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
