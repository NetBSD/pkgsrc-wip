# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:48 thomasklausner Exp $

DISTNAME=	slideml-1.1.0
CATEGORIES=	graphics
MASTER_SITES=	https://opensource.conformal.com/snapshots/slideml/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opensource.conformal.com/wiki/slideml
COMMENT=	HTML slide generator based on SlideML
LICENSE=	isc

USE_LANGUAGES=			# none
USE_TOOLS+=			perl
REPLACE_PERL+=			slideml.pl
DEPENDS+=			p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
NO_BUILD=			yes
WRKSRC=				${WRKDIR}/${DISTNAME}
INSTALLATION_DIRS=		bin

.include "../../mk/bsd.prefs.mk"

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.

DATA_DIR=	${DESTDIR}${PREFIX}/share/slideml
DOC_DIR=	${DESTDIR}${PREFIX}/share/doc/slideml
EG_DIR=		${DESTDIR}${PREFIX}/share/examples/slideml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slideml.pl ${DESTDIR}${PREFIX}/bin/slideml.pl
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/slideml_spec.txt ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/license ${DOC_DIR}
	${INSTALL_DATA_DIR} ${DATA_DIR}
	${INSTALL_DATA} ${WRKSRC}/slidy.css ${DATA_DIR}
	${INSTALL_DATA} ${WRKSRC}/slidy.js ${DATA_DIR}
	${INSTALL_DATA_DIR} ${EG_DIR}
	${INSTALL_DATA} ${WRKSRC}/examples/slides.sml ${EG_DIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
