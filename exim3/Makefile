# $NetBSD: Makefile,v 1.6 2003/11/30 05:18:01 grantbeattie Exp $

DISTNAME=	exim-3.36
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim3/ \
		http://public.planetmirror.com.au/pub/exim/exim3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

USE_PERL5=	YES
USE_PKGINSTALL=	YES

BUILD_DEFS+=		EXIM_USER EXIM_GROUP

PKG_SYSCONFSUBDIR?=	exim
EGDIR=			${PREFIX}/share/examples/exim
MAKE_ENV+=		INST_CONFIGURE_FILE="${EGDIR}/configure"
CONF_FILES=		${EGDIR}/configure ${PKG_SYSCONFDIR}/configure
MESSAGE_SUBST+=		EGDIR="${EGDIR}"

RCD_SCRIPTS=		exim

OWN_DIRS_PERMS=		/var/log/exim ${EXIM_USER} ${EXIM_GROUP} 0750
OWN_DIRS_PERMS+=	/var/spool/exim ${EXIM_USER} ${EXIM_GROUP} 0750

PKG_USERS=		${EXIM_USER}:${EXIM_GROUP}:8:Exim\\ mail\\ server\\ user:/var/mail:/sbin/nologin
PKG_GROUPS=		${EXIM_GROUP}

.include "../../mk/bsd.prefs.mk"

_GZIP_CMD!=		${ECHO} ${GZIP_CMD} | ${SED} -e 's/ .*//'
FILES_SUBST+=		GZIP_CMD="${_GZIP_CMD}"
FILES_SUBST+=		GZCAT="${GZCAT}"

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/Local/Makefile.netbsd \
		> ${WRKSRC}/Local/Makefile

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} /var/log/exim
	${CHMOD} 750 /var/log/exim
	strip ${WRKSRC}/build*/exim
	strip ${WRKSRC}/build*/exim_dbmbuild
	strip ${WRKSRC}/build*/exim_tidydb
	strip ${WRKSRC}/build*/exim_fixdb
	strip ${WRKSRC}/build*/exim_dumpdb
	strip ${WRKSRC}/build*/exim_lock

post-build:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
		${FILESDIR}/mailer.conf.exim \
		> ${WRKDIR}/mailer.conf

post-install:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
		${FILESDIR}/exim_newaliases
		> ${PREFIX}/sbin/exim_newaliases
	${CHMOD} ugo+x ${PREFIX}/sbin/exim_newaliases
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EGDIR}
	${CP} ${FILESDIR}/exim.8 ${PREFIX}/man/man8/exim.8

.include "../../mk/bsd.pkg.mk"
