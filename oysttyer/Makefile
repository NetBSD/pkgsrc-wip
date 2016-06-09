# $NetBSD$

DISTNAME=	oysttyer-2.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=oysttyer/}

MAINTAINER=	pkgsrc-wip@NetBSD.org
HOMEPAGE=	https://github.com/oysttyer/oysttyer/
COMMENT=	Interactive command-line Twitter client
LICENSE=	ffsl-license

WRKSRC=		${WRKDIR}/oysttyer-2.5.0
USE_LANGUAGES=	# none
USE_TOOLS+=	perl

NO_BUILD=	yes

REPLACE_PERL+=	oysttyer.pl

AUTO_MKDIRS=	yes

do-install:
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} oysttyer.pl ${DESTDIR}${PREFIX}/bin/oysttyer

.include "../../mk/bsd.pkg.mk"
