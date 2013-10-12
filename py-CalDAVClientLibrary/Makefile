# $NetBSD: Makefile,v 1.1 2013/10/12 13:37:17 thomasklausner Exp $

DISTNAME=	CalDAVClientLibrary-11755
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time net
MASTER_SITES=	# manually packaged from SVN

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.calendarserver.org/
COMMENT=	CalDAV library for python used by CalendarServer
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/CalDAVClientLibrary/trunk
USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
