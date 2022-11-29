# $NetBSD$

DISTNAME=	CROPSR
PKGNAME=	cropsr-0.0.0.44
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=H2muller/}
GITHUB_TAG=	7168556560c4f191fbbd4444fc2be75003abb6db
GITHUB_TYPE=	tag

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/H2muller/CROPSR
COMMENT=	Complex genome-wide CRISPR gRNA design and validation
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}
USE_LANGUAGES=	# none
NO_BUILD=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	CROPSR.py
REPLACE_PYTHON+=	cropsr_functions.py
REPLACE_PYTHON+=	prmrdsgn2.py

INSTALLATION_DIRS+=	bin share/doc/cropsr share/examples/cropsr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/CROPSR.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cropsr_functions.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/prmrdsgn2.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/cropsr
	${INSTALL_DATA} ${WRKSRC}/sample_data/output.csv ${DESTDIR}${PREFIX}/share/examples/cropsr
	${INSTALL_DATA} ${WRKSRC}/sample_data/sample_genome.fa ${DESTDIR}${PREFIX}/share/examples/cropsr
	${INSTALL_DATA} ${WRKSRC}/sample_data/sample_genome.gff ${DESTDIR}${PREFIX}/share/examples/cropsr

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
