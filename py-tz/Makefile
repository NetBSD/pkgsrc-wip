# $NetBSD: Makefile,v 1.2 2006/11/11 11:31:05 shattered Exp $

TZ_VERSION=	2006g
DISTNAME=	pytz-${TZ_VERSION}
PKGNAME=	${PYPKGPREFIX}-tz-${TZ_VERSION}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytz/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://pytz.sourceforge.net/
COMMENT=	Python interface to Olson tz database

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
