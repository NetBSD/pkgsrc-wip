# $NetBSD: Makefile,v 1.2 2012/10/03 11:53:15 ahp-nils Exp $
#

DISTNAME=	mashpodder-svn37
PKGNAME=	mashpodder-svn-37
CATEGORIES=	net
MASTER_SITES=	https://mashpodder.googlecode.com/files/

MAINTAINER=	ahp-nils@users.sf.net
HOMEPAGE=	https://code.google.com/p/mashpodder/
COMMENT=	Podcatching client based on BashPodder
LICENSE=	gnu-gpl-v2

FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate
DEPENDS+=		wget-[0-9]*:../../net/wget
DEPENDS+=		rsync-[0-9]*:../../net/rsync
DEPENDS+=		curl-[0-9]*:../../www/curl
DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

PKG_DESTDIR_SUPPORT=	user-destdir
NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run sed:run awk:run
EGDIR=			${PREFIX}/share/examples/mashpodder
INSTALLATION_DIRS+=	bin ${EGDIR} share/mashpodder
AUTO_MKDIRS=		yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*sh[^ ]*
REPLACE.bash.new=	${PREFIX}/bin/bash
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
