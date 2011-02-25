# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:49 thomasklausner Exp $
#

DISTNAME=	python-ptrace-0.6.2
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ptrace/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://python-ptrace.hachoir.org/trac
COMMENT=	Trace system calls and debugger written in python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= 	yes

PYTHON_VERSIONS_ACCEPTED= 27 26 25

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
