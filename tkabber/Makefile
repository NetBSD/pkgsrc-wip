# $NetBSD: Makefile,v 1.4 2005/04/23 16:06:32 kristerw Exp $
#

DISTNAME=	tkabber-0.9.5beta
CATEGORIES=	chat
MASTER_SITES=	http://www.jabberstudio.org/files/tkabber/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tkabber.jabber.ru/en/
COMMENT=	Free and Open Source TCL/TK jabber client

DEPENDS+=	tcllib-[0-9]*:../../devel/tcllib
DEPENDS+=	bwidget-[0-9]*:../../wip/bwidget

NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/tkabber
DATADIR=	${PREFIX}/share/tkabber

SUBDIRS=	emoticons-tkabber \
		plugins           \
		jabberlib-tclxml  \
		pixmaps           \
		sounds            \
		textundo          \
		msgs              \
		mclistbox-1.02

do-install:
	${INSTALL_DATA_DIR} ${DATADIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${WRKSRC}/*.xrdb ${DATADIR}
	cd ${WRKSRC}/examples && ${PAX} -rwp e . ${EGDIR}
.for i in ${SUBDIRS}
	cd ${WRKSRC} && ${PAX} -rwp e ${i} ${DATADIR}
.endfor
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		-e "s,@DATADIR@,${DATADIR}," ${FILESDIR}/tkabber.sh \
		> ${WRKSRC}/tkabber
	${INSTALL_SCRIPT} ${WRKSRC}/tkabber ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
