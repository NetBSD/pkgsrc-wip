# $NetBSD: Makefile,v 1.13 2010/04/23 07:35:52 obache Exp $
#

DISTNAME=	ibus-anthy-1.2.1
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Anthy engine for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	kasumi-[0-9]*:../../inputmethod/kasumi
DEPENDS+=	ibus>=1.2.0.20100111:../../wip/ibus
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.15.2:../../x11/py-gtk2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config msgfmt gmake intltool

FIND_PREFIX:=	KASUMI_DIR=kasumi
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--with-kasumi-exec=${KASUMI_DIR}/bin/kasumi
CONFIGURE_ARGS+=	--with-kasumi-icon=${KASUMI_DIR}/share/kasumi/kasumi.png

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	engine/ibus-engine-anthy.in setup/ibus-setup-anthy.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
