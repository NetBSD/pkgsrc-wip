# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:55 shattered Exp $
PKGNAME=	samhain-2.2.5
DISTNAME=	samhain_signed-2.2.5
CATEGORIES=	security
MASTER_SITES=	http://la-samhna.de/archive/

MAINTAINER=	lavalamp@digitalfreaks.org
HOMEPAGE=	http://www.la-samhna.de/samhain/
COMMENT=	Open-source IDS/file integrity checking

GNU_CONFIGURE=	yes
WRKSRC=${WRKDIR}/${PKGNAME_NOREV}


RCD_SCRIPTS=	samhain
EGDIR=		${PREFIX}/share/examples/samhain

CONFIGURE_ARGS+="--with-pid-file=/var/run/samhain.pid"
CONFIGURE_ARGS+="--with-log-file=/var/log/samhain.log"
CONFIGURE_ARGS+="--with-state-dir=/var/run"
CONFIGURE_ARGS+="--with-data-file=${PREFIX}/etc/samhain.db"
CONFIGURE_ARGS+="--with-config-file=${PREFIX}/etc/samhainrc"

pre-extract:
	cd ${WRKDIR} && ${PAX} -r -pp -z -f ${DISTDIR}/${DISTNAME}.tar.gz
do-extract:
	cd ${WRKDIR} && ${PAX} -r -pp -z -f ${PKGNAME}.tar.gz
	${CP} ${FILESDIR}/samhainrc.netbsd ${WRKSRC}

do-install:
	cd ${WRKSRC} && ${MAKE} install

post-install:
        #@${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
