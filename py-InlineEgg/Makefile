# $NetBSD: Makefile,v 1.2 2004/05/02 21:58:42 blef Exp $
#

DISTNAME=		InlineEgg-1.02
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oss.corest.com/projects/inlineegg.html
COMMENT=		Python module for writing inline assembler programs

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22 23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
