# $NetBSD$

PKGNAME=	ARC-1.1.4
DISTNAME=	ibest-ARC-v1.1.4-beta-0-g3831cb8
CATEGORIES=	biology
MASTER_SITES=   ${MASTER_SITE_GITHUB:=ibest/ARC/tarball/master/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ibest.github.io/ARC/
COMMENT=	Genomics pipeline for de novo assemblies
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/ibest-ARC-3831cb8
USE_TOOLS+=	pax
USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

REPLACE_PYTHON+=	ARC/exceptions.py
REPLACE_PYTHON+=	ARC/runners/assembly_checker.py
REPLACE_PYTHON+=	ARC/runners/__init__.py
REPLACE_PYTHON+=	ARC/runners/base.py
REPLACE_PYTHON+=	ARC/runners/mapper.py
REPLACE_PYTHON+=	ARC/runners/finisher.py
REPLACE_PYTHON+=	ARC/runners/assembler.py
REPLACE_PYTHON+=	ARC/__init__.py
REPLACE_PYTHON+=	ARC/logger.py
REPLACE_PYTHON+=	ARC/queue.py
REPLACE_PYTHON+=	ARC/app.py
REPLACE_PYTHON+=	ARC/process_runner.py
REPLACE_PYTHON+=	ARC/spawn.py
REPLACE_PYTHON+=	ARC/config.py
REPLACE_PYTHON+=	ARC/functions.py
REPLACE_PYTHON+=        bin/ARC
REPLACE_PYTHON+=	test_data/unit_tests.py

DEPENDS+=	blat>=3.5:../../biology/blat
DEPENDS+=	SPAdes>=3.8.2:../../biology/SPAdes
DEPENDS+=	bowtie2>=2.2.9:../../biology/bowtie2
DEPENDS+=	${PYPKGPREFIX}-biopython>=1.63b:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=${PY_DISTVERSION}:../../databases/py-sqlite3

INSTALLATION_DIRS+=	share/doc/ARC share/examples/ARC
NONEXECUTABLE_FILES+=	test_data/clean test_data/runarc

post-extract:
.for f in ${NONEXECUTABLE_FILES}
	${CHMOD} a-x ${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/Pipeline.pdf ${DESTDIR}${PREFIX}/share/doc/ARC
	cd ${WRKSRC}/test_data && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/ARC
	${RM} -f ${DESTDIR}${PREFIX}/share/examples/ARC/runarc.orig

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
