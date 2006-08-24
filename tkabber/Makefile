# $NetBSD: Makefile,v 1.7 2006/08/24 18:26:46 cheusov Exp $
#

DISTNAME=	tkabber-0.9.9
CATEGORIES=	chat
MASTER_SITES=	http://jabberstudio.rediris.es/tkabber/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tkabber.jabber.ru/en/
COMMENT=	Free and Open Source TCL/TK jabber client

DEPENDS+=	tcllib-[0-9]*:../../devel/tcllib
DEPENDS+=	bwidget-[0-9]*:../../wip/bwidget

NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/tkabber
DATADIR=	${PREFIX}/share/tkabber
DOCDIR=		${PREFIX}/share/doc/tkabber

INSTALLATION_DIRS+=	${EGDIR} ${DATADIR} ${DOCDIR}

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

EXTRA_FILES=	AUTHORS README COPYING INSTALL ChangeLog

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR} #${WRKSRC}/*.xrdb ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXTRA_FILES} ${DOCDIR}
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
