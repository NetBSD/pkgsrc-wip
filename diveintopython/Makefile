# $NetBSD: Makefile,v 1.12 2013/01/22 02:58:12 othyro Exp $
#

DISTNAME=	diveintopython-html-5.4
PKGNAME=	${DISTNAME:S/-html//}
CATEGORIES=	misc
MASTER_SITES=	http://www.diveintopython.net/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.diveintopython.net/
COMMENT=	Free book for experienced Python programmers
LICENSE=	python-software-foundation

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
HTMLDIR=	share/doc/diveintopython
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	${HTMLDIR}/html/appendix
INSTALLATION_DIRS+=	${HTMLDIR}/html/dynamic_functions
INSTALLATION_DIRS+=	${HTMLDIR}/html/file_handling
INSTALLATION_DIRS+=	${HTMLDIR}/html/functional_programming
INSTALLATION_DIRS+=	${HTMLDIR}/html/getting_to_know_python
INSTALLATION_DIRS+=	${HTMLDIR}/html/html_processing
INSTALLATION_DIRS+=	${HTMLDIR}/html/http_web_services
INSTALLATION_DIRS+=	${HTMLDIR}/html/images/callouts
INSTALLATION_DIRS+=	${HTMLDIR}/html/installing_python
INSTALLATION_DIRS+=	${HTMLDIR}/html/native_data_types
INSTALLATION_DIRS+=	${HTMLDIR}/html/object_oriented_framework
INSTALLATION_DIRS+=	${HTMLDIR}/html/performance_tuning
INSTALLATION_DIRS+=	${HTMLDIR}/html/power_of_introspection
INSTALLATION_DIRS+=	${HTMLDIR}/html/refactoring
INSTALLATION_DIRS+=	${HTMLDIR}/html/regular_expressions
INSTALLATION_DIRS+=	${HTMLDIR}/html/scripts_and_streams
INSTALLATION_DIRS+=	${HTMLDIR}/html/soap_web_services
INSTALLATION_DIRS+=	${HTMLDIR}/html/toc ${HTMLDIR}/html/unit_testing
INSTALLATION_DIRS+=	${HTMLDIR}/html/xml_processing ${HTMLDIR}/py/kgp
INSTALLATION_DIRS+=	${HTMLDIR}/py/plural/stage1 ${HTMLDIR}/py/plural/stage2
INSTALLATION_DIRS+=	${HTMLDIR}/py/plural/stage3 ${HTMLDIR}/py/plural/stage4
INSTALLATION_DIRS+=	${HTMLDIR}/py/plural/stage5 ${HTMLDIR}/py/plural/stage6
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage1 ${HTMLDIR}/py/soundex/stage1
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage2 ${HTMLDIR}/py/soundex/stage2
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage3 ${HTMLDIR}/py/soundex/stage3
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage4 ${HTMLDIR}/py/soundex/stage4
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage5 ${HTMLDIR}/py/roman/stage6
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage7 ${HTMLDIR}/py/roman/stage8
INSTALLATION_DIRS+=	${HTMLDIR}/py/roman/stage9

do-install:
	${INSTALL_DATA} ${WRKSRC}/html/diveintopython.css \
		${DESTDIR}${PREFIX}/${HTMLDIR}/html/
	${INSTALL_DATA} ${WRKSRC}/html/history.xml \
		${DESTDIR}${PREFIX}/${HTMLDIR}/html/
	${INSTALL_DATA} ${WRKSRC}/html/index.html \
		${DESTDIR}${PREFIX}/${HTMLDIR}/html/
	for i in appendix dynamic_functions file_handling \
		functional_programming getting_to_know_python html_processing \
			http_web_services installing_python native_data_types \
				object_oriented_framework performance_tuning \
					power_of_introspection refactoring \
						regular_expressions \
							scripts_and_streams \
		soap_web_services toc unit_testing xml_processing; do \
			${INSTALL_DATA} ${WRKSRC}/html/$$i/*.html \
				${DESTDIR}${PREFIX}/${HTMLDIR}/html/$$i/; \
	done
	${INSTALL_DATA} ${WRKSRC}/html/images/*.png \
		${DESTDIR}${PREFIX}/${HTMLDIR}/html/images/
	${INSTALL_DATA} ${WRKSRC}/html/images/callouts/* \
		${DESTDIR}${PREFIX}/${HTMLDIR}/html/images/callouts/
	${INSTALL_DATA} ${WRKSRC}/py/*.py ${DESTDIR}${PREFIX}/${HTMLDIR}/py/
	${INSTALL_DATA} ${WRKSRC}/py/plural-rules.en \
		${DESTDIR}${PREFIX}/${HTMLDIR}/py/
	${INSTALL_DATA} ${WRKSRC}/py/kgp/* \
		${DESTDIR}${PREFIX}/${HTMLDIR}/py/kgp/
	for i in 1 2 3 4 5 6; do \
		${INSTALL_DATA} ${WRKSRC}/py/plural/stage$$i/* \
			${DESTDIR}${PREFIX}/${HTMLDIR}/py/plural/stage$$i/; \
	done
	for i in 1 2 3 4 5 6 7 8 9; do \
		${INSTALL_DATA} ${WRKSRC}/py/roman/stage$$i/* \
			${DESTDIR}${PREFIX}/${HTMLDIR}/py/roman/stage$$i/; \
	done
	for i in 1 2 3 4; do \
		${INSTALL_DATA} ${WRKSRC}/py/soundex/stage$$i/* \
			${DESTDIR}${PREFIX}/${HTMLDIR}/py/soundex/stage$$i/; \
	done

.include "../../mk/bsd.pkg.mk"
