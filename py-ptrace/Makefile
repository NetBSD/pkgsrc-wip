# $NetBSD: Makefile,v 1.6 2012/02/01 00:04:53 noud4 Exp $
#

DISTNAME=	python-ptrace-0.6.3
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ptrace/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://bitbucket.org/haypo/python-ptrace/wiki/Home
COMMENT=	python-ptrace is a Python binding of ptrace library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/python-ptrace-0.6.3

PYDISTUTILSPKG= 	yes

.include "../../lang/python/extension.mk"
.if ${PYVERSSUFFIX} == "2.4"
DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes
.endif
.include "../../mk/bsd.pkg.mk"
