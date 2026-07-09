# $NetBSD: Makefile,v 1.7 2012/10/07 16:22:53 asau Exp $

DISTNAME=	samhain_signed-4.5.3
PKGNAME=	samhain-4.5.3
CATEGORIES=	security
MASTER_SITES=	http://www.la-samhna.de/archive/

MAINTAINER=	lavalamp@digitalfreaks.org
HOMEPAGE=	https://www.la-samhna.de/samhain/
COMMENT=	Open-source IDS/file integrity checking
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

BUILD_DEFS+=	VARBASE
RCD_SCRIPTS=	samhain
EGDIR=		${PREFIX}/share/examples/samhain
CONF_FILES=	${EGDIR}/samhainrc ${PKG_SYSCONFDIR}/samhainrc

USE_TOOLS+=	pax

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-config-file=${PREFIX}/etc/samhainrc
CONFIGURE_ARGS+=	--with-data-file=${PREFIX}/etc/samhain.db
CONFIGURE_ARGS+=	--with-log-file=${VARBASE}/log/samhain.log
CONFIGURE_ARGS+=	--with-pid-file=${VARBASE}/run/samhain.pid
CONFIGURE_ARGS+=	--with-state-dir=${VARBASE}/run

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

post-extract:
	cd ${WRKDIR} && pax -r -pp -z -f ${PKGNAME}.tar.gz
	cp ${FILESDIR}/samhainrc.netbsd ${WRKSRC}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
