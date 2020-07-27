# $NetBSD: Makefile,v 1.16 2014/01/26 15:50:00 thomasklausner Exp $

DISTNAME=	sgmltools-lite-3.0.3
PKGREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sgmltools-lite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sgmltools-lite.sourceforge.net/
COMMENT=	Friendly Python interface to SGML software
LICENSE=	gnu-gpl-v2

DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	lynx-[0-9]*:../../www/lynx
DEPENDS+=	docbook-[0-9]*:../../textproc/docbook
DEPENDS+=	w3m-[0-9]*:../../www/w3m
DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
DEPENDS+=	iso12083-[0-9]*:../../textproc/iso12083
DEPENDS+=	iso8879-[0-9]*:../../textproc/iso8879


GNU_CONFIGURE=	YES
CONFIGURE_ENV=	PYTHON=${PYTHONBIN:Q}

PKG_SYSCONFSUBDIR=	sgml
EGDIR=			${PREFIX}/share/examples/sgmltools-lite
CONFIGURE_ARGS+=	--with-etcsgml=${EGDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

# Avoid using -s on /usr/pkg/bin/sgmltools
_STRIPFLAG_INSTALL=

SGML_CATALOGS=	${PKG_SYSCONFDIR}/catalog

CONF_FILES=	${EGDIR}/aliases ${PKG_SYSCONFDIR}/aliases
CONF_FILES+=	${EGDIR}/catalog ${PKG_SYSCONFDIR}/catalog
CONF_FILES+=	${EGDIR}/catalog.rh62 ${PKG_SYSCONFDIR}/catalog.rh62
CONF_FILES+=	${EGDIR}/catalog.suse ${PKG_SYSCONFDIR}/catalog.suse

pre-configure:

	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' \
		< ${WRKSRC}/bin/buildcat.in > ${WRKSRC}/bin/buildcat.in.new

	${SED} -e "s|@PREFIX@|${PREFIX}|g" \
		< ${FILESDIR}/catalog > ${WRKDIR}/catalog

	${CP} ${WRKSRC}/bin/buildcat.in.new ${WRKSRC}/bin/buildcat.in

post-install:

	${INSTALL_DATA} ${WRKDIR}/catalog ${EGDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
