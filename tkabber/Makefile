# $NetBSD: Makefile,v 1.5 2005/10/09 01:47:34 poppnk Exp $
#

DISTNAME=	tkabber-0.9.8
CATEGORIES=	chat
MASTER_SITES=	http://jabberstudio.rediris.es/tkabber/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tkabber.jabber.ru/en/
COMMENT=	Free and Open Source TCL/TK jabber client

DEPENDS+=	tcllib-[0-9]*:../../devel/tcllib
DEPENDS+=	bwidget-[0-9]*:../../wip/bwidget

NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/tkabber
DATADIR=	${PREFIX}/share/tkabber

# XXX this is also in the tkabber's Makefile
SUBDIRS=	emoticons-tkabber \
		aniemoteicons    \
		ifacetk           \
		plugins           \
		jabberlib-tclxml  \
		pixmaps           \
		sounds            \
		textundo          \
		msgs              \
		mclistbox-1.02

do-install:
	${INSTALL_DATA_DIR} ${DATADIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR} #${WRKSRC}/*.xrdb ${DATADIR}
	cd ${WRKSRC}/examples && ${PAX} -rwp e . ${EGDIR}
.for i in ${SUBDIRS}
	cd ${WRKSRC} && ${PAX} -rwp e ${i} ${DATADIR}
.endfor
	# TODO This must be a CLASS
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		-e "s,@DATADIR@,${DATADIR}," ${FILESDIR}/tkabber.sh \
		> ${WRKSRC}/tkabber
	${INSTALL_SCRIPT} ${WRKSRC}/tkabber ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
