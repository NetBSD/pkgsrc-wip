# $NetBSD: Makefile,v 1.4 2014/12/09 10:05:40 thomasklausner Exp $

DISTNAME=	CalDAVClientLibrary-14161
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time net
MASTER_SITES=	# manually packaged from SVN

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.calendarserver.org/
COMMENT=	CalDAV library for python used by CalendarServer
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/CalDAVClientLibrary
USE_LANGUAGES=	# none
EGG_NAME=	UNKNOWN-0.0.0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 13824

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
