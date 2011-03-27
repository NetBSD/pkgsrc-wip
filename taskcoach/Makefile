# $NetBSD: Makefile,v 1.2 2011/03/27 00:47:04 ryo-on Exp $
#

DISTNAME=	TaskCoach-1.2.12
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=taskcoach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.taskcoach.org/
COMMENT=	Task Coach is a simple open source todo manager
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.9.1:../../x11/py-wxWidgets

PYDISTUTILSPKG=	YES

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
