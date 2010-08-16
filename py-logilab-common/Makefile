# $NetBSD: Makefile,v 1.7 2010/08/16 10:39:11 jihbed Exp $
#

VERS=	0.50.3
DISTNAME=	logilab-common-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	logilab_common-${VERS}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/common/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-common
COMMENT=	Useful miscellaneous modules used by Logilab projects
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-extract:
	${MV} ${WRKSRC}/bin/pytest ${WRKSRC}/bin/pytest${PYVERSSUFFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pytest.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
