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
USE_TOOLS+=	cut diff
USE_LANGUAGES=	# none
NO_BUILD=	yes

DEPENDS+=	${PYPKGPREFIX}-argparse>=1.4.0:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.3.5:../../math/py-pandas

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	CROPSR.py
REPLACE_PYTHON+=	cropsr_functions.py
REPLACE_PYTHON+=	prmrdsgn2.py

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	cropsr prmrdsgn2
SUBST_VARS.prefix=	PREFIX

INSTALLATION_DIRS+=	bin libexec/cropsr share/doc/cropsr share/examples/cropsr

post-extract:
	${CP} ${FILESDIR}/cropsr ${WRKSRC}
	${CP} ${FILESDIR}/prmrdsgn2 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cropsr ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/prmrdsgn2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/CROPSR.py ${DESTDIR}${PREFIX}/libexec/cropsr
	${INSTALL_SCRIPT} ${WRKSRC}/cropsr_functions.py ${DESTDIR}${PREFIX}/libexec/cropsr
	${INSTALL_SCRIPT} ${WRKSRC}/prmrdsgn2.py ${DESTDIR}${PREFIX}/libexec/cropsr
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/cropsr
	${INSTALL_DATA} ${WRKSRC}/sample_data/output.csv ${DESTDIR}${PREFIX}/share/examples/cropsr
	${INSTALL_DATA} ${WRKSRC}/sample_data/sample_genome.fa ${DESTDIR}${PREFIX}/share/examples/cropsr
	${INSTALL_DATA} ${WRKSRC}/sample_data/sample_genome.gff ${DESTDIR}${PREFIX}/share/examples/cropsr

do-test:
	${DESTDIR}${PREFIX}/libexec/cropsr/CROPSR.py -h
	${DESTDIR}${PREFIX}/libexec/cropsr/CROPSR.py --cas9 --fasta ${WRKSRC}/sample_data/sample_genome.fa --gff ${WRKSRC}/sample_data/sample_genome.gff --output /tmp/output.csv
	${CUT} -f 2- -d ',' < ${WRKSRC}/sample_data/output.csv > /tmp/output1.csv
	${CUT} -f 2- -d ',' < /tmp/output.csv > /tmp/output2.csv
	@${ECHO} "NOTE: there should be at most a few rounding differences to the scores"
	${DIFF} -u /tmp/output1.csv /tmp/output2.csv

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
