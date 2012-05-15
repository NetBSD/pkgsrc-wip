# $NetBSD: Makefile,v 1.3 2012/05/15 14:08:40 noud4 Exp $
#

PKG_REVISION=		1
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2
# XXX			tools AND libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

.include "options.mk"

PKGCONFIG_OVERRIDE=	libgda-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-report-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-ui-4.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda-4.0
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--disable-crypto
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIG_SHELL=	bash

SUBST_CLASSES+=		local
SUBST_STAGE.local= 	post-patch
SUBST_FILES.local= 	configure
SUBST_SED.local+=	-e "s|@LOCAL@|${PREFIX}|g"
SUBST_MESSAGE.local=	"Fixing configure prefix."

# XXX also needs reportlab
REPLACE_PYTHON+=	libgda-report/RML/trml2pdf/trml2pdf.py
REPLACE_PYTHON+=	libgda-report/RML/trml2html/trml2html.py

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons
	${CP} ${DESTDIR}${PREFIX}/share/libgda-4.0/pixmaps/gda-control-center.png ${DESTDIR}${PREFIX}/share/icons

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
