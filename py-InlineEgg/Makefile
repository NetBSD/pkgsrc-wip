# $NetBSD: Makefile,v 1.3 2004/10/19 15:34:42 adrian_p Exp $
#

DISTNAME=		InlineEgg-1.07
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oss.corest.com/projects/inlineegg.html
COMMENT=		Python module for writing inline assembler programs

LICENSE=		inlineegg-license

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22 21 23pth 22pth 21pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
