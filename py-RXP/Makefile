# $NetBSD: Makefile,v 1.2 2004/05/02 21:51:10 blef Exp $

DISTNAME=	pyRXP-0-9
PKGNAME=	${PYPKGPREFIX}-rxp-0.9
CATEGORIES=	textproc
MASTER_SITES=	http://www.reportlab.com/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.reportlab.com/xml/pyrxp.html
COMMENT=	Validating XML parser for Python

WRKSRC=		${WRKDIR}
MAKE_ENV+=	LIBERROR=0
USE_BUILDLINK3=	YES
PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
