# $NetBSD: Makefile,v 1.20 2004/11/04 22:22:18 adrian_p Exp $
#

DISTNAME=	bugzilla-2.18rc3
CATEGORIES=	www
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/webtools/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
DEPENDS+=	p5-File-Spec>=0.82:../../devel/p5-File-Spec
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Tabs+Wrap>=2001.0131:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate
DEPENDS+=	p5-DBD-mysql>=2.1010:../../databases/p5-DBD-mysql

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_BUILDLINK3=	YES
NO_BUILD=	YES
USE_PKGINSTALL=	YES
PERL5_REQD+=	5.6.0

BUILDLINK_DEPENDS.p5-DBI+=		p5-DBI>=1.36
BUILDLINK_DEPENDS.mysql-client+=	mysql-client>=3.23.41

BZ_DB_DATABASE?=bugs
BZ_DB_HOST?=	localhost
BZ_DB_PORT?=	3306
BZ_DB_USER?=	bugs
BZ_DB_PASS?=	changemeplease
BZ_WEB_GROUP?=	www
MYSQL_SOCLOC?=	/tmp/mysql.sock

BUILD_DEFS+=	BZ_DB_DATABASE BZ_DB_HOST BZ_DB_PORT BZ_DB_USER BZ_DB_PASS \
		BZ_WEB_GROUP MYSQL_SOCLOC

MESSAGE_SUBST+=	BZDIR=${BZDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

BZDIR=		${PREFIX}/share/bugzilla
EGDIR=		${PREFIX}/share/examples/bugzilla
DOCDIR=		${PREFIX}/share/doc/bugzilla
CONF_FILES=	${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf \
		${EGDIR}/localconfig ${BZDIR}/localconfig

REPLACE_PERL=	*.pl *.cgi

SUBST_CLASSES=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	bugzilla.conf localconfig
SUBST_SED.conf=		-e "s|@BZ_DB_HOST@|${BZ_DB_HOST}|g" 		\
			-e "s|@BZ_WEB_GROUP@|${BZ_WEB_GROUP}|g"		\
			-e "s|@BZ_DB_PORT@|${BZ_DB_PORT}|g" 		\
			-e "s|@BZ_DB_DATABASE@|${BZ_DB_DATABASE}|g" 	\
			-e "s|@BZ_DB_USER@|${BZ_DB_USER}|g" 		\
			-e "s|@BZ_DB_PASS@|${BZ_DB_PASS}|g"		\
			-e "s|@MYSQL_SOCLOC@|${MYSQL_SOCLOC}|g"		\
			-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@BZDIR@|${BZDIR}|g"
SUBST_MESSAGE.conf=	"Fixing configuration files."

post-extract:
	@${FIND} ${WRKSRC}/docs/images -type d -name CVS | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC}/template -type d -name CVS | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC}/skins -type d -name CVS | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC}/template -type f -name ".cvsignore" | ${XARGS} \
		${RM} -f
	@${CP} ${FILESDIR}/bugzilla.conf ${WRKSRC}
	@${CP} ${FILESDIR}/localconfig ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${BZDIR}
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla/Auth
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla/Template/Plugin
	${INSTALL_DATA_DIR} ${BZDIR}/css
	${INSTALL_DATA_DIR} ${BZDIR}/js
	${INSTALL_DATA_DIR} ${BZDIR}/template
	${INSTALL_DATA_DIR} ${BZDIR}/skins
	${INSTALL_DATA_DIR} ${BZDIR}/docs/html
	${INSTALL_DATA_DIR} ${BZDIR}/docs/images
	${INSTALL_DATA} ${WRKSRC}/docs/txt/Bugzilla-Guide.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/rel_notes.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICKSTART ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING-pre-2.8 ${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${BZDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla.pm ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla/*.pm ${BZDIR}/Bugzilla
	${INSTALL_DATA} ${WRKSRC}/Bugzilla/Auth/*.pm ${BZDIR}/Bugzilla/Auth
	${INSTALL_DATA} ${WRKSRC}/Bugzilla/Template/Plugin/*.pm \
		${BZDIR}/Bugzilla/Template/Plugin
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/1x1.gif ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/ant.jpg ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/padlock.png ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/localconfig ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.dtd ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/js/*.js ${BZDIR}/js
	${INSTALL_DATA} ${WRKSRC}/duplicates.xul ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/css/*.css ${BZDIR}/css
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${BZDIR}/docs/html
	cd ${WRKSRC}/template && ${PAX} -rw . ${BZDIR}/template
	cd ${WRKSRC}/skins && ${PAX} -rw . ${BZDIR}/skins
	cd ${WRKSRC}/docs/images && ${PAX} -rw . ${BZDIR}/docs/images
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${BZDIR}/template
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${BZDIR}/skins

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
