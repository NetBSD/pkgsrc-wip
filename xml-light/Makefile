# $NetBSD: Makefile,v 1.4 2013/01/19 08:38:27 othyro Exp $
#

DISTNAME=	xml-light-2.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://tech.motion-twin.com/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tech.motion-twin.com/xmllight.html
COMMENT=	Xml-Light is a minimal XML parser & printer for OCaml
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/xml-light
USE_LANGUAGES=	c
USE_TOOLS+=	gmake

SUBST_CLASSES+=		destdir
SUBST_MESSAGE.destdir=	Fixing DESTDIR.
SUBST_STAGE.destdir=	post-build
SUBST_FILES.destdir=	Makefile
SUBST_SED.destdir=	-e "s|INSTALLDIR=|INSTALLDIR=${DESTDIR}|1"

INSTALLATION_DIRS+=	lib/ocaml

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/ocaml/dtd.mli
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/ocaml/xml.mli
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/ocaml/xmlParser.mli

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
