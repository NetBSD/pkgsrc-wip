# $NetBSD: Makefile,v 1.2 2015/06/25 09:12:04 ahp-nils Exp $

DISTNAME=		logrotate-3.9.1
CATEGORIES=		sysutils

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://fedorahosted.org/logrotate/
COMMENT=		Daemon to rotate, compress, remove and mail system log files
LICENSE=		gnu-gpl-v2

SVN_ROOT.logrotate=	http://svn.fedorahosted.org/svn/logrotate/trunk
SVN_REPOSITORIES=	logrotate
WRKSRC=			${WRKDIR}/logrotate
PKGREVISION=		${_SVN_PKGVERSION:S/.//g}
USE_TOOLS+=		gmake gzip:run gunzip:run mail:run automake autoconf

BUILD_DEPENDS+=		autogen-[0-9]*:../../devel/autogen
BUILD_DEPENDS+=		autoconf>=2.52:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.6.0:../../devel/automake
BUILD_DEPENDS+=		libtool-base>=1.4.2:../../devel/libtool-base

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
HAS_CONFIGURE=		yes
NO_EXPORT_CPP=		yes

CONFIGURE_ENV+=		STATEFILE=\"${VARBASE}/db/logrotate.status\"
CONFIGURE_ENV+=		DEFAULT_MAIL_COMMAND=\"${MAIL_CMD:Q}\"
CONFIGURE_ENV+=		COMPRESS_COMMAND=\"${GZIP_CMD:[1]:Q}\"
CONFIGURE_ENV+=		UNCOMPRESS_COMMAND=\"${GUNZIP_CMD:[1]:Q}\"

BUILD_DEFS+=		VARBASE
EGDIR=			${PREFIX}/share/examples/logrotate
CONF_FILES=		${EGDIR}/logrotate.conf ${PKG_SYSCONFDIR}/logrotate.conf
OWN_DIRS=		${PKG_SYSCONFDIR}/logrotate.d
MESSAGE_SUBST+=		EGDIR=${EGDIR}
INSTALLATION_DIRS+=	${EGDIR} ${PKG_SYSCONFDIR} ${OWN_DIRS}
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	examples/logrotate-default
SUBST_FILES.paths+=	examples/logrotate.cron
SUBST_FILES.paths+=	logrotate.8
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	VARBASE
SUBST_VARS.paths+=	PKG_SYSCONFDIR

DOCDIR=			share/doc/logrotate

pre-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/logrotate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate-default ${DESTDIR}${EGDIR}/logrotate.conf
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate.cron ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/logrotate.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/logrotate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/popt/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
