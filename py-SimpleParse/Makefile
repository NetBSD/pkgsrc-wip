# $NetBSD: Makefile,v 1.1.1.1 2003/06/12 06:24:43 mjasm Exp $
#

DISTNAME=		SimpleParse-2.0.0
PKGNAME=       	${PYPKGPREFIX}-SimpleParse-2.0.0
CATEGORIES=		textproc

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simpleparse/}
EXTRACT_SUFX= 	.zip

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://simpleparse.sourceforge.net/
COMMENT=		a simple parser generator for mxTextTools text-tagging engine.

DEPENDS+=      	egenix-mx-base>=2.0.4:../../wip/egenix-mx-base

PYDISTUTILSPKG= yes
PYTHON_VERSION_REQD=22pth
USE_BUILDLINK2= YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
