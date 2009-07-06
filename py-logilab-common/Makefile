# $NetBSD: Makefile,v 1.2 2009/07/06 22:33:21 jihbed Exp $
#

DISTNAME=	logilab-common-0.42.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/common/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-common
COMMENT=	Useful miscellaneous modules used by Logilab projects
#LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Pyro>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../wip/py-ipython
#DEPENDS+=	${PYPKGPREFIX}-omniORBpy>=3.2:../../wip/py-omniORBpy
DEPENDS+=	pydb>=1.26:../../wip/pydb
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django


PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25
PY_PATCHPLIST=		yes

.include "options.mk"


INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pytest.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
