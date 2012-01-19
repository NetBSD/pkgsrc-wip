# $NetBSD: Makefile,v 1.2 2012/01/19 16:28:54 noud4 Exp $
#

LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2
# XXX			tools AND libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

.include "options.mk"

PKGCONFIG_OVERRIDE=	libgda-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-report-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-ui-4.0.pc.in
PKGCONFIG_OVERRIDE+=	libgda-xslt-4.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda-4.0
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

#CONFIGURE_ARGS+=	--with-bdb=no
CONFIGURE_ARGS+=	--disable-crypto
CONFIG_SHELL=	bash

# XXX also needs reportlab
REPLACE_PYTHON+=	libgda-report/RML/trml2pdf/trml2pdf.py
REPLACE_PYTHON+=	libgda-report/RML/trml2html/trml2html.py

TEST_TARGET=		check

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
