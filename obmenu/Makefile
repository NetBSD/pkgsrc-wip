# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	obmenu-1.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=obmenu/}

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://obmenu.sourceforge.net/
COMMENT=	Openbox menu editor
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

SUBST_CLASSES+=		obmenu
SUBST_MESSAGE.obmenu=	Fixing LOCALBASE path.
SUBST_STAGE.obmenu=	pre-patch
SUBST_FILES.obmenu=	obmenu
SUBST_SED.obmenu+=	-e 's|/usr/share|${LOCALBASE}/share|g'

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	${WRKSRC}/obmenu ${WRKSRC}/obxml.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
