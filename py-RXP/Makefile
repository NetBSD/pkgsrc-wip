# $NetBSD: Makefile,v 1.4 2006/05/01 01:32:11 shattered Exp $

DISTNAME=	pyRXP-0-9
PKGNAME=	${PYPKGPREFIX}-rxp-0.9
CATEGORIES=	textproc
MASTER_SITES=	http://www.reportlab.org/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.reportlab.org/pyrxp.html
COMMENT=	Validating XML parser for Python

WRKSRC=		${WRKDIR}
MAKE_ENV+=	LIBERROR=0
PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
