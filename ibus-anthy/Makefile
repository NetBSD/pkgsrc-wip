# $NetBSD: Makefile,v 1.7 2010/01/12 11:29:35 obache Exp $
#

DISTNAME=	ibus-anthy-1.2.0.20091127
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Anthy engine for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	kasumi-[0-9]*:../../inputmethod/kasumi

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config msgfmt gmake intltool

FIND_PREFIX:=	KASUMI_DIR=kasumi
.include "../../mk/find-prefix.mk"

SUBST_CLASSES+=		kasumi
SUBST_STAGE.kasumi=	pre-configure
SUBST_FILES.kasumi=	setup/anthyprefs.py
SUBST_SED.kasumi=	-e 's|/usr/bin/kasumi|${KASUMI_DIR}/bin/kasumi|g'

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	engine/ibus-engine-anthy.in setup/ibus-setup-anthy.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../devel/swig/buildlink3.mk"
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
