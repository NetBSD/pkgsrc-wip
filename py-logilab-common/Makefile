# $NetBSD: Makefile,v 1.4 2010/04/19 09:43:39 jihbed Exp $
#

VERS=			0.49.0
DISTNAME=	logilab-common-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	logilab_common-${VERS}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/common/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-common
COMMENT=	Useful miscellaneous modules used by Logilab projects
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pytest.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
