# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	teng-python-2.0.0
PKGNAME=	${PYPKGPREFIX}-teng-2.0.0

CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=teng/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://teng.sourceforge.net/
COMMENT=	Python binding for teng

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../wip/teng/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
