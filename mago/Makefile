# $NetBSD: Makefile,v 1.1.1.1 2010/05/26 16:11:17 jihbed Exp $
#

DISTNAME=	mago-0.2
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/mago/trunk/mago-0.2/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/mago
COMMENT=	Library and harness for desktop testing
LICENSE=	gnu-lgpl-v3

DEPENDS+=	ldtp>=2.0.6:../../wip/ldtp

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
REPLACE_PYTHON+=	bin/mago

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
