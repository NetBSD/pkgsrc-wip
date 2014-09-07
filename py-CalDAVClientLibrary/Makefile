# $NetBSD: Makefile,v 1.3 2014/09/07 20:59:24 thomasklausner Exp $

DISTNAME=	CalDAVClientLibrary-13824
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time net
MASTER_SITES=	# manually packaged from SVN

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.calendarserver.org/
COMMENT=	CalDAV library for python used by CalendarServer
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/CalDAVClientLibrary/trunk
USE_LANGUAGES=	# none
EGG_NAME=	UNKNOWN-0.0.0

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 13824

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
