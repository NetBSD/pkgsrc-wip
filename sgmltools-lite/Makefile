# $NetBSD: Makefile,v 1.5 2004/04/26 14:45:22 adrian_p Exp $

DISTNAME=	sgmltools-lite-3.0.3
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sgmltools-lite/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://sgmltools-lite.sourceforge.net/
COMMENT=	Friendly Python interface to SGML software

DEPENDS+=	jade-[0-9]*:../../textproc/jade
DEPENDS+=	lynx-[0-9]*:../../www/lynx
DEPENDS+=	docbook-[0-9]*:../../textproc/docbook
DEPENDS+=	w3m-[0-9]*:../../www/w3m
DEPENDS+= 	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
DEPENDS+=	iso12083-[0-9]*:../../textproc/iso12083
DEPENDS+=	iso8879-[0-9]*:../../textproc/iso8879

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
CONFIGURE_ENV=	PYTHON=${PYTHONBIN}

PKG_SYSCONFSUBDIR=	sgml
CONFIGURE_ARGS+=	--with-etcsgml=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${LOCALBASE}/share

PYTHON_VERSIONS_ACCEPTED=	22 22pth 23 23pth 21 21pth 20
_STRIPFLAG_INSTALL=

SGML_CATALOGS=	${PKG_SYSCONFDIR}/catalog

pre-configure:

	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' \
		< ${WRKSRC}/bin/buildcat.in > ${WRKSRC}/bin/buildcat.in.new

	${SED} -e "s|@PREFIX@|${PREFIX}|g" \
		< ${FILESDIR}/catalog > ${WRKDIR}/catalog

	${CP} ${WRKSRC}/bin/buildcat.in.new ${WRKSRC}/bin/buildcat.in

post-install:

	${INSTALL_DATA} ${WRKDIR}/catalog ${PKG_SYSCONFDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
