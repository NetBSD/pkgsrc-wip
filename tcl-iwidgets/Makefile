# $NetBSD: Makefile,v 1.5 2014/02/22 08:20:57 obache Exp $
#

DISTNAME=	iwidgets-4.0.1
PKGNAME=	tcl-${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/iwidgets
COMMENT=	Object-oriented mega-widget set which extends Tcl/Tk
LICENSE=	2-clause-bsd # ?

DEPENDS+=	tcl>=8.6:../../lang/tcl

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	grep

INSTALLATION_DIRS+=	lib/iwidgets lib/iwidgets/incoming ${PKGMANDIR}/mann
INSTALLATION_DIRS+=	share/doc/html/iwidgets share/doc/iwidgets
INSTALLATION_DIRS+=	share/examples/iwidgets/images
INSTALLATION_DIRS+=	share/examples/iwidgets/incoming

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.tcl ${DESTDIR}${PREFIX}/lib/iwidgets/ && \
	${INSTALL_DATA} scripts/* ${DESTDIR}${PREFIX}/lib/iwidgets/ && \
	${INSTALL_DATA} README.txt ${DESTDIR}${PREFIX}/share/doc/iwidgets/
	cd ${WRKSRC}/demos && \
	for FILE in `ls -1 | ${GREP} -v -E '(html|images)'`; do \
		${INSTALL_DATA} "$$FILE" ${DESTDIR}${PREFIX}/share/examples/iwidgets/; \
	done && \
	${INSTALL_DATA} images/* ${DESTDIR}${PREFIX}/share/examples/iwidgets/images/; \
	cd ${WRKSRC}/demos/html && \
	${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/html/iwidgets/; \
	cd ${WRKSRC}/incoming && \
	${INSTALL_DATA} README ${DESTDIR}${PREFIX}/share/doc/iwidgets/README.incoming && \
	${INSTALL_DATA} demos/* ${DESTDIR}${PREFIX}/share/examples/iwidgets/incoming && \
	${INSTALL_MAN} doc/collapsablewidget.n ${DESTDIR}${PREFIX}/${PKGMANDIR}/mann/ && \
	${INSTALL_DATA} src/* ${DESTDIR}${PREFIX}/lib/iwidgets/incoming/

.include "../../mk/bsd.pkg.mk"
