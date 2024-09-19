# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:19 asau Exp $
#

DISTNAME=	dbglog-python-1.5.0
PKGNAME=	${PYPKGPREFIX}-dbglog-1.5.0

CATEGORIES=	python misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbglog/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://opensource.seznam.cz/DBGlog
COMMENT=	Python binding for dbglog

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../wip/libdbglog/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
