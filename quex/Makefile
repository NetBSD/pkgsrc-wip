# $NetBSD$

DISTNAME=	quex-0.65.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quex/DOWNLOAD/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quex.sourceforge.net/
COMMENT=	Lexical analyzer generator
LICENSE=	gnu-lgpl-v2.1

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*.py

USE_LANGUAGES=	# none

NO_BUILD=	yes

QUEX_DIR=	share/quex

INSTALLATION_DIRS=	${PREFIX}/bin
INSTALLATION_DIRS+=	${PREFIX}/${QUEX_DIR}

post-extract:
	${RUN} find ${WRKSRC} -name '*.orig' -exec rm -f {} \;

do-install:
	${RUN} cp -r ${WRKSRC}/* ${DESTDIR}${PREFIX}/${QUEX_DIR}
	${RUN} ${INSTALL_SCRIPT} ${FILESDIR}/quex.sh ${DESTDIR}${PREFIX}/${QUEX_DIR}/quex.sh
	${RUN} ln -s ${PREFIX}/${QUEX_DIR}/quex.sh ${DESTDIR}${PREFIX}/bin/quex

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
