# $NetBSD: Makefile,v 1.1.1.1 2003/10/05 17:50:14 adrian_p Exp $

DISTNAME=	sgmltools-lite-3.0.3
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sgmltools-lite/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://sgmltools-lite.sourceforge.net/
COMMENT=	Friendly Python interface to SGML software

DEPENDS+=	jade-[0-9]*:../../textproc/jade
DEPENDS+=	lynx-[0-9]*:../../www/lynx
DEPENDS+=	docbook-[0-9]*:../../textproc/docbook

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ENV=	PYTHON=${PYTHONBIN}

PKG_SYSCONFSUBDIR=	sgml
CONFIGURE_ARGS+=	--with-etcsgml=${PKG_SYSCONFDIR}

PYTHON_VERSIONS_ACCEPTED=	22 22pth 23 23pth 21 21pth 20
_STRIPFLAG_INSTALL=

pre-configure:

	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' \
		< ${WRKSRC}/bin/buildcat.in > ${WRKSRC}/bin/buildcat.in.new

	${CP} ${WRKSRC}/bin/buildcat.in.new ${WRKSRC}/bin/buildcat.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
