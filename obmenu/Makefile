# $NetBSD: Makefile,v 1.2 2010/04/22 16:47:10 othyro Exp $
#

DISTNAME=	obmenu-1.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=obmenu/}

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://obmenu.sourceforge.net/
COMMENT=	Openbox menu editor
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		obmenu
SUBST_MESSAGE.obmenu=	Fixing LOCALBASE path.
SUBST_STAGE.obmenu=	pre-patch
SUBST_FILES.obmenu=	obmenu
SUBST_SED.obmenu+=	-e 's|/usr/share|${LOCALBASE}/share|g'

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	${WRKSRC}/obmenu ${WRKSRC}/obxml.py

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
