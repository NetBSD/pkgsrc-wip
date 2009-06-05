# $NetBSD: Makefile,v 1.1.1.1 2009/06/05 21:49:29 jihbed Exp $
#

DISTNAME=	python-ptrace-0.6
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ptrace/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://python-ptrace.hachoir.org/trac
COMMENT=	Trace system calls and debugger written in python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG= 	yes

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
