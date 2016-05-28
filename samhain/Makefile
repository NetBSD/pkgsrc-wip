# $NetBSD: Makefile,v 1.7 2012/10/07 16:22:53 asau Exp $

DISTNAME=	samhain_signed-2.4.4
PKGNAME=	samhain-2.4.4
CATEGORIES=	security
MASTER_SITES=	http://www.la-samhna.de/archive/

MAINTAINER=	lavalamp@digitalfreaks.org
HOMEPAGE=	http://www.la-samhna.de/samhain/
COMMENT=	Open-source IDS/file integrity checking


BUILD_DEFS+=	VARBASE
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
RCD_SCRIPTS=	samhain
EGDIR=		${PREFIX}/share/examples/samhain
CONF_FILES=	${EGDIR}/samhainrc ${PKG_SYSCONFDIR}/samhainrc
USE_TOOLS+=	pax

CONFIGURE_ARGS+=	--with-config-file=${PREFIX}/etc/samhainrc
CONFIGURE_ARGS+=	--with-data-file=${PREFIX}/etc/samhain.db
CONFIGURE_ARGS+=	--with-log-file=${VARBASE}/log/samhain.log
CONFIGURE_ARGS+=	--with-pid-file=${VARBASE}/run/samhain.pid
CONFIGURE_ARGS+=	--with-state-dir=${VARBASE}/run
GNU_CONFIGURE=		yes

post-extract:
	cd ${WRKDIR} && pax -r -pp -z -f ${PKGNAME}.tar.gz
	cp ${FILESDIR}/samhainrc.netbsd ${WRKSRC}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
