# $NetBSD: Makefile,v 1.7 2015/06/10 13:43:17 ahp-nils Exp $

CATEGORIES=	net

COMMENT=	Podcatching client based on BashPodder
LICENSE=	gnu-gpl-v2

GHCOMMIT=	98aa00d9828b0a2e361c01a2ee583d3505d0067c
DISTNAME=	${GHCOMMIT}
PKGNAME=	mashpodder-0.4.9
PKGREVISION=	1
MASTER_SITES=	https://github.com/chessgriffin/mashpodder/archive/

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/chessgriffin/mashpodder/

DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run sed:run awk:run curl:run wget:run
EGDIR=			${PREFIX}/share/examples/mashpodder
INSTALLATION_DIRS+=	bin ${EGDIR} share/mashpodder
AUTO_MKDIRS=		yes
WRKSRC=			${WRKDIR}/mashpodder-${GHCOMMIT}

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*sh[^ ]*
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	*.sh

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	mashpodder.sh
SUBST_VARS.paths=	PREFIX

do-install:
	${INSTALL_DATA} ${WRKSRC}/mp.conf ${DESTDIR}${EGDIR}/mp.conf
	${INSTALL_DATA} ${WRKSRC}/sample-wrapper-for-cron.sh ${DESTDIR}${EGDIR}/sample-wrapper-for-cron.sh
	${INSTALL_DATA} ${WRKSRC}/parse_enclosure.xsl ${DESTDIR}${PREFIX}/share/mashpodder/parse_enclosure.xsl
	${INSTALL_SCRIPT} ${WRKSRC}/mashpodder.sh ${DESTDIR}${PREFIX}/bin/mashpodder

.include "../../mk/bsd.pkg.mk"
