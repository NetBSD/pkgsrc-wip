# $NetBSD: Makefile,v 1.3 2003/09/14 22:00:37 marc Exp $
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
USE_BUILDLINK2=		yes
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
