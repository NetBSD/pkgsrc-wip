# $NetBSD: Makefile,v 1.1.1.1 2003/07/08 14:49:25 adrian_p Exp $

DISTNAME=	mailman-${PKG_VERSION}
PKGNAME=	mailman21-${PKG_VERSION}
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_GNU:=mailman/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.list.org
COMMENT=	the GNU Mailing List Manager

.include "../../mk/bsd.prefs.mk"

CONFLICTS=		mailman-2.0.[0-9]*

NO_BUILD=		YES
USE_PKGINSTALL=		YES
USE_BUILDLINK2=		YES
NO_BIN_ON_FTP=		requires compiled-in hardcoded uid/gid/hostname
NO_BIN_ON_CDROM=	${NO_BIN_ON_FTP}

PKG_VERSION=		2.1.2
MAILMAN_USER?= 		mailman
MAILMAN_GROUP?= 	mailman
MAILMAN_MAILGROUP?=	guest # group of user 'daemon'
MAILMAN_MAILHOST!=	${UNAME} -n
MAILMAN_URLHOST!=	${UNAME} -n
PKG_GROUPS=		${MAILMAN_GROUP}
PKG_USERS=		${MAILMAN_USER}:${MAILMAN_GROUP}::Mailman\\ user::${SH}

MMDOCS=		ACKNOWLEDGMENTS BUGS FAQ INSTALL NEWS README README.BSD \
		README.EXIM README.LINUX README.NETSCAPE README.POSTFIX \
		README.QMAIL README.SENDMAIL README.USERAGENT TODO UPGRADING

MAILMAN_DATADIR=	/var/db/mailman
EXECDIR=		${PREFIX}/lib/mailman
EGDIR=			${PREFIX}/share/examples/mailman
DOCDIR=			${PREFIX}/share/doc/mailman

PKG_SYSCONFSUBDIR?=	httpd
APACHE_USER=		www
#BUILD_USER!=		${ID} -u -n

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}
MESSAGE_SUBST+=		EXECDIR=${EXECDIR}
MESSAGE_SUBST+=		MAILMAN_USER=${MAILMAN_USER}

FILES_SUBST+=		EXECDIR=${EXECDIR}
FILES_SUBST+=		MAILMAN_USER=${MAILMAN_USER}
FILES_SUBST+=		MAILMAN_GROUP=${MAILMAN_GROUP}
FILES_SUBST+=		MAILMAN_DATADIR=${MAILMAN_DATADIR}

MAILMAN_CONFIGURE_ARGS=	--with-python=${PYTHONBIN}
MAILMAN_CONFIGURE_ARGS+=	--prefix=${EXECDIR}
MAILMAN_CONFIGURE_ARGS+=	--with-var-prefix=${MAILMAN_DATADIR}
MAILMAN_CONFIGURE_ARGS+=	--with-username=${MAILMAN_USER}
MAILMAN_CONFIGURE_ARGS+=	--with-groupname=${MAILMAN_GROUP}
MAILMAN_CONFIGURE_ARGS+=	--with-mail-gid=${MAILMAN_MAILGROUP}
MAILMAN_CONFIGURE_ARGS+=	--with-cgi-gid=${APACHE_USER}
MAILMAN_CONFIGURE_ARGS+=	--without-permcheck
MAILMAN_CONFIGURE_ARGS+=	--with-mailhost=${MAILMAN_MAILHOST}
MAILMAN_CONFIGURE_ARGS+=	--with-urlhost=${MAILMAN_URLHOST}

OWN_DIRS+=		${MAILMAN_DATADIR}
OWN_DIRS_PERMS+=	${EXECDIR} root ${MAILMAN_GROUP} 0755

CONF_FILES+=    ${EGDIR}/mailman.conf ${PKG_SYSCONFDIR}/mailman.conf
CONF_FILES+=    ${EXECDIR}/Mailman/mm_cfg.py.dist ${EXECDIR}/Mailman/mm_cfg.py

PYTHON_VERSIONS_ACCEPTED=   21 22

PYTHON_PATCH_SCRIPTS=	Mailman/Archiver/pipermail.py Mailman/Post.py \
			admin/bin/Release.py admin/bin/faq2ht.py \
			admin/bin/mm2do bin/add_members bin/arch \
			bin/b4b5-archfix bin/change_pw bin/check_db \
			bin/check_perms bin/cleanarch bin/clone_member \
			bin/config_list bin/convert.py bin/dumpdb \
			bin/find_member bin/fix_url.py bin/genaliases \
			bin/inject bin/list_admins bin/list_lists \
			bin/list_members bin/list_owners bin/mailmanctl \
			bin/mmsitepass bin/msgfmt.py bin/newlist \
			bin/pygettext.py bin/qrunner bin/remove_members \
			bin/rmlist bin/sync_members bin/transcheck \
			bin/unshunt bin/update bin/version bin/withlist \
			contrib/check_perms_grsecurity.py \
			contrib/qmail-to-mailman.py contrib/rotatelogs.py \
			cron/bumpdigests cron/checkdbs cron/disabled \
			cron/gate_news cron/mailpasswds	cron/nightly_gzip \
			cron/senddigests tests/onebounce.py

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailman.conf.dist \
		>  ${WRKDIR}/mailman.conf.dist

	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/archives
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/archives/public
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0771 \
		${MAILMAN_DATADIR}/archives/private
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/data
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/lists
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/locks
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/logs
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/qfiles
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m0775 \
		${MAILMAN_DATADIR}/spam

do-install:
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m775 ${EXECDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; \
	./configure ${MAILMAN_CONFIGURE_ARGS}; \
	${MAKE} install
	cd ${WRKSRC}; \
	for FILE in ${MMDOCS}; do \
		${INSTALL_DATA} $$FILE ${DOCDIR}/; \
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} mailman.conf.dist ${EGDIR}/mailman.conf
	${CHOWN} -R root ${EXECDIR}
	${CHMOD} -R g-w ${EXECDIR}
	#${CHOWN} -R ${BUILD_USER} ${WRKSRC}
	${CHMOD} -R a+w ${WRKSRC}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
