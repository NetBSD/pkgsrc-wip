# $NetBSD: Makefile,v 1.1.1.1 2010/08/16 22:29:17 nthauvin Exp $
#

DISTNAME=	pyexiv2-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	http://launchpad.net/pyexiv2/0.2.x/0.2.2/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nico@orgrim.net
HOMEPAGE=	http://tilloy.net/dev/pyexiv2/
COMMENT=	Python binding to Exiv2
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
BUILDLINK_ABI_DEPENDS.exiv2+=	exiv2>=0.20

PYTHON_VERSIONS_ACCEPTED=	26 25
PY_PATCHPLIST=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
	DESTDIR=${DESTDIR:Q}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
	DESTDIR=${DESTDIR:Q} install

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
