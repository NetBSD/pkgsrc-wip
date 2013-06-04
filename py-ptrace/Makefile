# $NetBSD: Makefile,v 1.11 2013/06/04 07:45:23 thomasklausner Exp $
#

DISTNAME=	python-ptrace-0.6.4
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ptrace/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://bitbucket.org/haypo/python-ptrace/wiki/Home
COMMENT=	Python binding of ptrace
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

ONLY_FOR_PLATFORM=	FreeBSD-*-x86_64  FreeBSD-*-i386 Linux-*-*

PYTHON_VERSIONS_INCLUDE_3X= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG= 	yes

post-extract:
	${MV} ${WRKSRC}/strace.py ${WRKSRC}/strace.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/gdb.py ${WRKSRC}/gdb.py${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
