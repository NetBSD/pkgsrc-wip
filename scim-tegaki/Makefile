# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:23:00 obache Exp $
#

DISTNAME=	scim-tegaki-0.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.1/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://www.tegaki.org/releases/0.1/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../wip/tegaki-pygtk
DEPENDS+=	scim-python>=0.1.13rc1:../../wip/scim-python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix= 	src/__init__.py
SUBST_SED.prefix=	-e 's|/usr/local/share|${PREFIX}/share|g'
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
