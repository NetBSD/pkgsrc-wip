# $NetBSD: Makefile,v 1.15 2017/01/26 20:12:32 nils Exp $

DISTNAME=		${GHCOMMIT}
PKGNAME=		logrotate-3.21.0.20230401
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=logrotate/logrotate/archive/}

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://github.com/logrotate/logrotate/
COMMENT=		Daemon to rotate, compress, remove and mail system log files
LICENSE=		gnu-gpl-v2

GHCOMMIT=		eb94f32dcc585e31c880418d82c38521076e882a
USE_TOOLS+=		gmake gzip:run gunzip:run mail:run autoreconf autoconf automake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
NO_EXPORT_CPP=		yes

WRKSRC=			${WRKDIR}/logrotate-${GHCOMMIT}
CONFIGURE_ENV+=		STATEFILE=\"${VARBASE}/db/logrotate.status\"
CONFIGURE_ENV+=		DEFAULT_MAIL_COMMAND=\"${MAIL_CMD:Q}\"
CONFIGURE_ENV+=		COMPRESS_COMMAND=\"${GZIP_CMD:[1]:Q}\"
CONFIGURE_ENV+=		UNCOMPRESS_COMMAND=\"${GUNZIP_CMD:[1]:Q}\"
CONFIGURE_ARGS+=	--with-state-file-path="${VARBASE}/db/logrotate.status"

BUILD_DEFS+=		VARBASE

MESSAGE_SUBST+=		EGDIR=${EGDIR}
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	examples/logrotate.conf
SUBST_FILES.paths+=	examples/logrotate.cron
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR

CONF_FILES=		${EGDIR}/logrotate.conf ${PKG_SYSCONFDIR}/logrotate.conf \
			${EGDIR}/btmp ${PKG_SYSCONFDIR}/logrotate.d/btmp \
			${EGDIR}/wtmp \
			${EGDIR}/logrotate.service

OWN_DIRS=		${PKG_SYSCONFDIR}/logrotate.d

EGDIR=			share/examples/logrotate

INSTALLATION_DIRS+=	${EGDIR}
pre-configure:
	cd ${WRKSRC} && autoreconf -fiv
post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/logrotate.conf
	${INSTALL_DATA} ${WRKSRC}/examples/btmp \
		${DESTDIR}${PREFIX}/${EGDIR}/btmp
	${INSTALL_DATA} ${WRKSRC}/examples/wtmp \
		${DESTDIR}${PREFIX}/${EGDIR}/wtmp
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate.cron \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate.service \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
