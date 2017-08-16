# $NetBSD: Makefile,v 1.10 2013/02/12 18:35:01 shattered Exp $
#

DISTNAME=	chora-h3-2.1.1
PKGNAME=	${DISTNAME:S/h3-//1}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.horde.org/pub/chora/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.horde.org/apps/chora/
COMMENT=	Another CVS-via-web system
LICENSE=	gnu-gpl-v2

#DEPENDS+=	cvs>=1.11.20:../../devel/scmcvs
DEPENDS+=	horde>=2.2.4:../../www/horde

USE_LANGUAGES=	# empty
NO_BUILD=	YES

CHORADIR=	${PREFIX}/share/chora
INSTALLATION_DIRS+=	${CHORADIR}/config ${CHORADIR}/docs ${CHORADIR}/js/src
INSTALLATION_DIRS+=	${CHORADIR}/lib/Block
INSTALLATION_DIRS+=	${CHORADIR}/locale/cs_CZ/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/da_DK/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/de_DE/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/en_US
INSTALLATION_DIRS+=	${CHORADIR}/locale/es_ES/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/fi_FI/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/fr_FR/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/it_IT/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/nb_NO/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/nl_NL/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/pl_PL/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/pt_BR/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/ro_RO/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/ru_RU/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/sk_SK/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/sv_SE/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/zh_CN/LC_MESSAGES
INSTALLATION_DIRS+=	${CHORADIR}/locale/zh_TW/LC_MESSAGES ${CHORADIR}/po
INSTALLATION_DIRS+=	${CHORADIR}/templates/annotate
INSTALLATION_DIRS+=	${CHORADIR}/templates/checkout
INSTALLATION_DIRS+=	${CHORADIR}/templates/cvsgraph
INSTALLATION_DIRS+=	${CHORADIR}/templates/diff/hr
INSTALLATION_DIRS+=	${CHORADIR}/templates/directory
INSTALLATION_DIRS+=	${CHORADIR}/templates/history ${CHORADIR}/templates/log
INSTALLATION_DIRS+=	${CHORADIR}/templates/patchsets
INSTALLATION_DIRS+=	${CHORADIR}/templates/stats
INSTALLATION_DIRS+=	${CHORADIR}/themes/burntorange
INSTALLATION_DIRS+=	${CHORADIR}/themes/graphics
INSTALLATION_DIRS+=	${CHORADIR}/themes/hordeweb
INSTALLATION_DIRS+=	${CHORADIR}/themes/silver/graphics
INSTALLATION_DIRS+=	${CHORADIR}/themes/themed_graphics

do-install:
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${DESTDIR}${CHORADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${CHORADIR}
	${INSTALL_DATA} ${WRKSRC}/config/* ${DESTDIR}${CHORADIR}/config/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${CHORADIR}/docs/
	${INSTALL_DATA} ${WRKSRC}/js/*.js ${DESTDIR}${CHORADIR}/js/
	${INSTALL_DATA} ${WRKSRC}/js/src/* ${DESTDIR}${CHORADIR}/js/src/
	${INSTALL_DATA} ${WRKSRC}/lib/.htaccess ${DESTDIR}${CHORADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/*.php ${DESTDIR}${CHORADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/Block/* ${DESTDIR}${CHORADIR}/lib/Block/
	${INSTALL_DATA} ${WRKSRC}/locale/.htaccess ${DESTDIR}${CHORADIR}/locale/
	for i in cs_CZ da_DK de_DE es_ES fi_FI fr_FR it_IT nb_NO nl_NL pl_PL \
		pt_BR ro_RO ru_RU sk_SK sv_SE zh_CN zh_TW; do \
		${INSTALL_DATA} ${WRKSRC}/locale/$$i/LC_MESSAGES/chora.mo \
			${DESTDIR}${CHORADIR}/locale/$$i/LC_MESSAGES/; \
	done
	for i in de_DE en_US es_ES fi_FI; do \
		${INSTALL_DATA} ${WRKSRC}/locale/$$i/help.xml \
			${DESTDIR}${CHORADIR}/locale/$$i/; \
	done
	${INSTALL_DATA} ${WRKSRC}/po/* ${DESTDIR}${CHORADIR}/po/
	${INSTALL_DATA} ${WRKSRC}/templates/.htaccess \
		${DESTDIR}${CHORADIR}/templates/
	${INSTALL_DATA} ${WRKSRC}/templates/*.inc \
		${DESTDIR}${CHORADIR}/templates/
	for i in annotate checkout cvsgraph 'diff/hr' directory history log \
		patchsets stats; do \
			${INSTALL_DATA} ${WRKSRC}/templates/$$i/*.inc \
				${DESTDIR}${CHORADIR}/templates/$$i/; \
	done
	${INSTALL_DATA} ${WRKSRC}/themes/screen.css ${DESTDIR}${CHORADIR}/themes
	for i in burntorange graphics hordeweb 'silver/graphics'; do \
		${INSTALL_DATA} ${WRKSRC}/themes/$$i/* \
			${DESTDIR}${CHORADIR}/themes/$$i/; \
	done

.include "../../mk/bsd.pkg.mk"
