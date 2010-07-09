# $NetBSD: Makefile,v 1.4 2010/07/09 18:40:32 jihbed Exp $
#

DISTNAME=	logilab-astng-0.20.1
EGG_NAME=	logilab_astng-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/astng/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-astng
COMMENT=	Extend Python abstract syntax tree
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24 23

do-test:
	cd ${WRKSRC} && ${SH} test/fulltest.sh

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
