# $NetBSD: Makefile,v 1.4 2006/05/20 04:38:00 yomram Exp $
#

DISTNAME=		viewcvs-0.9.4
CATEGORIES=		devel www
MASTER_SITES=		http://viewcvs.sourceforge.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://viewcvs.sourceforge.net/
COMMENT=		View CVS repositories via WWW. No HTTP server needed

NO_BUILD= 		YES
PYTHON_PATCH_SCRIPTS=	viewcvs-install standalone.py

VIEWCVSDIR=	share/viewcvs
PLIST_SUBST+=	VIEWCVSDIR=${VIEWCVSDIR:Q}
MESSAGE_SUBST+=	VIEWCVSDIR=${VIEWCVSDIR:Q}

do-install:
	${SED} -e "s|@INSTALLDIR@|${PREFIX}/${VIEWCVSDIR}|" ${WRKSRC}/viewcvs-install > ${WRKSRC}/viewcvs-install.pkgsrc
	(cd ${WRKSRC} && ${PYTHONBIN} ./viewcvs-install.pkgsrc)

# patch-aa is not need if this do-install is used instead of above.
#do-install:
#	(cd ${WRKSRC} && \
#	${ECHO} "${PREFIX}/${VIEWCVSDIR}" | ${PYTHONBIN} ./viewcvs-install )

#.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
