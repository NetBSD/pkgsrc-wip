# $NetBSD: Makefile,v 1.4 2012/01/03 15:25:31 jihbed Exp $
#

DISTNAME=	python-ptrace-0.6.3
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ptrace/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://bitbucket.org/haypo/python-ptrace/wiki/Home
COMMENT=	python-ptrace is a Python binding of ptrace library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/python-ptrace-0.6.3

PYDISTUTILSPKG= 	yes

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
