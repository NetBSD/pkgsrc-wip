# $NetBSD$

DISTNAME=	quex-0.65.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quex/DOWNLOAD/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quex.sourceforge.net/
COMMENT=	Lexical analyzer generator
LICENSE=	gnu-lgpl-v2.1

REPLACE_PYTHON+=	quex-exe.py
REPLACE_PYTHON+=	demo/benchmark/run/make_gnuplot.py
REPLACE_PYTHON+=	quex/output/cpp/token_id_maker.py
REPLACE_PYTHON+=	quex/output/cpp/analyzer_class.py
REPLACE_PYTHON+=	quex/input/files/core.py
REPLACE_PYTHON+=	quex/input/setup.py
REPLACE_PYTHON+=	quex/engine/misc/interval_handling.py.orig
REPLACE_PYTHON+=	quex/engine/misc/interval_handling.py
REPLACE_PYTHON+=	quex/engine/misc/file_in.py
REPLACE_PYTHON+=	quex/engine/codec_db/core.py
REPLACE_PYTHON+=	quex/engine/state_machine/construction/sequentialize.py
REPLACE_PYTHON+=	quex/engine/state_machine/construction/repeat.py
REPLACE_PYTHON+=	quex/engine/state_machine/construction/setup_post_context.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-interference2.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-prepare_cautious_recipes.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-accumulate.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-categorize.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-do.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-interference5.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-resolve.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-interference1.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-interference4.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-interference3.py
REPLACE_PYTHON+=	quex/engine/analyzer/examine/TEST-later/test-setup_initial_springs.py
REPLACE_PYTHON+=	quex/blackboard.py.orig
REPLACE_PYTHON+=	quex/blackboard.py
REPLACE_PYTHON+=	quex/DEFINITIONS.py

USE_LANGUAGES=	# none

NO_BUILD=	yes

QUEX_DIR=	share/quex
FILESDIR=	files
FILES_SUBST+=	QUEX_DIR=${PREFIX}${QUEX_DIR}
FILES_SUBST+=	PREFIX=${PREFIX}

INSTALLATION_DIRS=	${PREFIX}/bin
INSTALLATION_DIRS+=	${PREFIX}/${QUEX_DIR}

post-extract:
	${RUN} find ${WRKSRC} -name '*.orig' -exec rm -f {} \;

do-install:
	${RUN} cp -r ${WRKSRC}/* ${DESTDIR}${PREFIX}/${QUEX_DIR}
	${RUN} ${INSTALL_SCRIPT} ${FILESDIR}/quex ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
