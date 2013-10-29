# $NetBSD: Makefile,v 1.12 2013/10/29 21:15:09 jihbed Exp $

VERSION=	1.0.0
DISTNAME=	pylint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/p/pylint/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.logilab.org/project/pylint
COMMENT=	Python code static checker
LICENSE=    	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-astroid>=1.0.1:../../wip/py-astroid

USE_LANGUAGES=	# none

DOCDIR= ${PREFIX}/share/doc/pylint
INSTALLATION_DIRS=  ${DOCDIR} ${PKGMANDIR}/man1

PYTHON_VERSIONS_INCLUDE_3X=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

BUILDLINK_API_DEPENDS.py-logilab-common+= ${PYPKGPREFIX}-logilab-common>=0.53.0
.include "../../devel/py-logilab-common/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
