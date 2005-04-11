# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:56 tvierling Exp $

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
PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
