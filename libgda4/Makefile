# $NetBSD: Makefile,v 1.1 2012/01/19 13:31:22 drochner Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

.include "options.mk"

PKGCONFIG_OVERRIDE=	libgda-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-report-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-sqlite-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-xslt-4.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda-4.0
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no
CONFIGURE_ARGS+=	--disable-crypto
CONFIG_SHELL=	bash

# XXX also needs reportlab
REPLACE_PYTHON+=	libgda-report/RML/trml2pdf/trml2pdf.py
REPLACE_PYTHON+=	libgda-report/RML/trml2html/trml2html.py

TEST_TARGET=		check

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
