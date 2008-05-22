# $NetBSD: Makefile,v 1.3 2008/05/22 15:38:48 tnn2 Exp $

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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
