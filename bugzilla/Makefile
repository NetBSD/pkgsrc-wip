# $NetBSD: Makefile,v 1.7 2004/04/13 10:43:41 adrian_p Exp $
#

DISTNAME=	bugzilla-2.16.4
CATEGORIES=	www
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/webtools/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql>=1.2209:../../databases/p5-DBD-mysql
DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-Template-Toolkit>=2.07:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Tabs+Wrap>=2001.0131:../../wip/p5-Text-Tabs+Wrap
DEPENDS+=	p5-File-Spec>=0.82:../../devel/p5-File-Spec
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=       {p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:${PERL5_PKGSRCDIR}
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
#
# these are optional
#
DEPENDS+=	gd>=1.19:../../graphics/gd
DEPENDS+=	p5-Chart-[0-9]*:../../wip/p5-Chart
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

BZDIR?=		${PREFIX}/share/bugzilla

SENDMAIL?=	/usr/sbin/sendmail
BZ_DB_DATABASE?=bugs
BZ_DB_HOST?=	localhost
BZ_DB_PORT?=	3306
BZ_DB_USER?=	bugs
BZ_DB_PASS?=	changemeplease

BZ_WEB_GROUP?=	www

MESSAGE_SUBST+=	BZDIR=${BZDIR} EXDIR=${PREFIX}/share/examples/bugzilla \
		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

post-extract:
	${FIND} ${WRKSRC}/template -type d -name CVS | ${XARGS} ${RM} -fr
	${FIND} ${WRKSRC}/template -type f -name ".cvsignore" | ${XARGS} ${RM} -f

do-build:
	for f in ${WRKSRC}/*.pl ${WRKSRC}/Bug.pm ${WRKSRC}/*.cgi \
	${WRKSRC}/processmail ${WRKSRC}/syncshadowdb; do \
		[ -f $$f.BAK ] || ${MV} $$f $$f.BAK ; \
		${SED} -e 's#\#\!/usr/bonsaitools/bin/perl#\#\!${PREFIX}/bin/perl#g' \
			-e "s#/usr/lib/sendmail#${SENDMAIL}#g" \
			< $$f.BAK > $$f; \
	done

	for f in localconfig bugzilla.conf; do \
		${SED} -e 's#@PREFIX@#${PREFIX}#g' \
			-e 's#@BZDIR@#${BZDIR}#g' \
			-e 's#@BZ_DB_HOST@#${BZ_DB_HOST}#g' \
			-e 's#@BZ_WEB_GROUP@#${BZ_WEB_GROUP}#g' \
			-e 's#@BZ_DB_PORT@#${BZ_DB_PORT}#g' \
			-e 's#@BZ_DB_DATABASE@#${BZ_DB_DATABASE}#g' \
			-e 's#@BZ_DB_USER@#${BZ_DB_USER}#g' \
			-e 's#@BZ_DB_PASS@#${BZ_DB_PASS}#g' \
			< ${FILESDIR}/$$f > ${WRKSRC}/$$f; \
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bugzilla
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bugzilla
	${INSTALL_DATA_DIR} ${BZDIR}
	${INSTALL_DATA_DIR} ${BZDIR}/css
	${INSTALL_DATA_DIR} ${BZDIR}/template
	${INSTALL_DATA} ${WRKSRC}/docs/txt/Bugzilla-Guide.txt ${PREFIX}/share/doc/bugzilla
	${INSTALL_DATA} ${WRKSRC}/docs/rel_notes.txt ${PREFIX}/share/doc/bugzilla
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bugzilla
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${PREFIX}/share/doc/bugzilla
	${INSTALL_DATA} ${WRKSRC}/UPGRADING-pre-2.8 ${PREFIX}/share/doc/bugzilla
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${BZDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pm ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/1x1.gif ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/ant.jpg ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.conf ${PREFIX}/share/examples/bugzilla
	${INSTALL_DATA} ${WRKSRC}/localconfig ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.dtd ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/processmail ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/syncshadowdb ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/css/*.css ${BZDIR}/css
	cd ${WRKSRC}/template && ${PAX} -rw . ${BZDIR}/template
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${BZDIR}/template

.include "../../mk/bsd.pkg.mk"
