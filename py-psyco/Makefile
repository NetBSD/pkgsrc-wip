# $NetBSD: Makefile,v 1.1.1.1 2003/09/21 19:27:48 mpasternak Exp $

DISTNAME=       psyco-1.1.1-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=     devel
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=     dotz@irc.pl
HOMEPAGE=       http://psyco.sf.net/
COMMENT=        Python JIT and execution accelerator

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

.include	"../../lang/python/extension.mk"
.include        "../../mk/bsd.pkg.mk"
