# $NetBSD: Makefile,v 1.2 2003/07/13 18:25:54 marc Exp $
#

DISTNAME=		SimpleParse-2.0.0
PKGNAME=     		${PYPKGPREFIX}-SimpleParse-2.0.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=simpleparse/}
EXTRACT_SUFX= 		.zip

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://simpleparse.sourceforge.net/
COMMENT=		Simple parser generator for mxTextTools text-tagging engine

PYDISTUTILSPKG=		yes
PYTHON_VERSION_REQD=	22pth
USE_BUILDLINK2=		yes

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
