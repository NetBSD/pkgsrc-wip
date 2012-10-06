# $NetBSD: Makefile,v 1.4 2012/10/06 17:55:25 asau Exp $
#

DISTNAME=	pychm-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnochm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gnochm.sourceforge.net/
COMMENT=	Python bindings for the CHMLIB library

PYDISTUTILSPKG=		yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
