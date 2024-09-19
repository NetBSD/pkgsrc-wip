# $NetBSD: Makefile,v 1.9 2021/06/29 08:41:59 nia Exp $

DISTNAME=	hotdoc-0.13.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hotdoc/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=hotdoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hotdoc.github.io/
COMMENT=	API documentation system
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
#DEPENDS+=	${PYPKGPREFIX}-cchardet-[0-9]*:../../devel/py-cchardet
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
#DEPENDS+=	${PYPKGPREFIX}-dbus-deviation-[0-9]*:../../devel/py-dbus-deviation
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pkgconfig-[0-9]*:../../devel/py-pkgconfig
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-schema-[0-9]*:../../wip/py-schema
#DEPENDS+=	${PYPKGPREFIX}-toposort-[0-9]*:../../devel/py-toposort
#DEPENDS+=	${PYPKGPREFIX}-wheezy.template-[0-9]*:../../devel/py-wheezy.template

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

REPLACE_SH+=	hotdoc/extensions/gi/transition_scripts/translate_sections.sh

.include "../../lang/python/egg.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
