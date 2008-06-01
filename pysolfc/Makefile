# $NetBSD: Makefile,v 1.2 2008/06/01 15:46:07 thomasklausner Exp $
#

DISTNAME=	PySolFC-1.1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysolfc/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
#DISTFILES+=	${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://pysolfc.sourceforge.net/
COMMENT=	Python solitaire game collection

DEPENDS+=	${PYPKGPREFIX}-imagingtk>=1.1:../../graphics/py-imagingtk
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.1:../../x11/py-gtk2

CONFLICTS=	pysol-[0-9]*

#PKG_DESTDIR_SUPPORT=	user-destdir

#NO_BUILD=	yes
#PLIST_SRC=	${WRKDIR}/PLIST.src

PYTHON_VERSIONS_ACCEPTED=	25 24 23

CARDSETS=	PySolFC-Cardsets-1.1

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man6

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing data directory paths.
SUBST_FILES.fix-paths=		pysollib/settings.py
SUBST_SED.fix-paths=		-e 's,/usr,${PREFIX},g'

SUBST_CLASSES+=			rename-script
SUBST_STAGE.rename-script=	pre-configure
SUBST_MESSAGE.rename-script=	Fixing script name.
SUBST_FILES.rename-script=	setup.py
SUBST_SED.rename-script=	-e 's,pysol.py,pysol,g'

pre-configure:
	cd ${WRKSRC} && ${MV} pysol.py pysol

PLIST_SUBST+=	PKGMANDIR="${PKGMANDIR}"

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/pysol.6 ${PREFIX}/${PKGMANDIR}/man6

#do-install:
#	${SED} -e "s|@pkgdatadir@|${PREFIX}/share/pysol|" \
#		-e "s|python|${PYTHONBIN}|" \
#		< ${WRKSRC}/pysol > ${DESTDIR}${PREFIX}/bin/pysol
#	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/pysol
#	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
#	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pysol
#	(cd ${WRKSRC}/data; tar cf - *) | \
#		(cd ${DESTDIR}${PREFIX}/share/pysol; tar xf -)
#	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
#		(cd ${DESTDIR}${PREFIX}/share/pysol; tar xf -)
#
#post-install:
#	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
#	@(cd ${DESTDIR}${PREFIX}; \
#	  ${FIND} share/pysol \( -type f -or -type l \) -print | \
#	    ${SORT} >> ${PLIST_SRC}; \
#	  for DIR in `${FIND} share/pysol -type d -print | ${SORT} -r`; do \
#	  ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
#	  done)

#.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
