# $NetBSD: Makefile,v 1.12 2004/11/04 00:01:23 adrian_p Exp $
#

DISTNAME=	bugzilla-2.18rc3
CATEGORIES=	www
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/webtools/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
#DEPENDS+=	{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:${PERL5_PKGSRCDIR}
DEPENDS+=	p5-File-Spec>=0.82:../../devel/p5-File-Spec
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Tabs+Wrap>=2001.0131:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate
DEPENDS+=	mysql-client>=3.23.41:../../databases/mysql3-client
DEPENDS+=	p5-DBI>=1.36:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql>=2.1010:../../databases/p5-DBD-mysql
#
# these are optional
#
DEPENDS+=	p5-Chart>=1.0:../../graphics/p5-Chart
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-PatchReader>=0.9.4:../../devel/p5-PatchReader
DEPENDS+=	gd>=1.20:../../graphics/gd

NO_BUILDLINK=	YES
NO_BUILD=	YES
USE_PKGINSTALL=	YES
PERL5_REQD+=	5.6.0

BZ_DB_DATABASE?=bugs
BZ_DB_HOST?=	localhost
BZ_DB_PORT?=	3306
BZ_DB_USER?=	bugs
BZ_DB_PASS?=	changemeplease
BZ_WEB_GROUP?=	www

BUILD_DEFS+=	BZ_DB_DATABASE BZ_DB_HOST BZ_DB_PORT BZ_DB_USER BZ_DB_PASS \
		BZ_WEB_GROUP

MESSAGE_SUBST+=	BZDIR=${BZDIR} EGDIR=${EGDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

BZDIR=		${PREFIX}/share/bugzilla
EGDIR=		${PREFIX}/share/examples/bugzilla
DOCDIR=		${PREFIX}/share/doc/bugzilla
#OWN_DIRS+=	${EGDIR}
CONF_FILES=	${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf \
		${EGDIR}/localconfig ${BZDIR}/localconfig

REPLACE_PERL=	*.pl *.cgi

SUBST_CLASSES=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	bugzilla.conf localconfig
SUBST_SED.conf=		-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@BZDIR@|${BZDIR}|g" \
			-e "s|@BZ_DB_HOST@|${BZ_DB_HOST}|g" \
			-e "s|@BZ_WEB_GROUP@|${BZ_WEB_GROUP}|g" \
			-e "s|@BZ_DB_PORT@|${BZ_DB_PORT}|g" \
			-e "s|@BZ_DB_DATABASE@|${BZ_DB_DATABASE}|g" \
			-e "s|@BZ_DB_USER@|${BZ_DB_USER}|g" \
			-e "s|@BZ_DB_PASS@|${BZ_DB_PASS}|g"
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

.include "../../mk/bsd.pkg.mk"
