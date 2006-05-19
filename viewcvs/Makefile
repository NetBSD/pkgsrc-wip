# $NetBSD: Makefile,v 1.3 2006/05/19 16:51:40 ykomatsu Exp $
#

DISTNAME=		viewcvs-0.9.2
CATEGORIES=		devel www
MASTER_SITES=		http://viewcvs.sourceforge.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://viewcvs.sourceforge.net/
COMMENT=		View CVS repositories via WWW. No HTTP server needed

NO_BUILD= 		#defined
PYTHON_PATCH_SCRIPTS=	viewcvs-install standalone.py

do-install:
	${SED} -e "s|@INSTALLDIR@|${PREFIX}/${PKGNAME}|" ${WRKSRC}/viewcvs-install > ${WRKSRC}/viewcvs-install.pkgsrc
	(cd ${WRKSRC} && ${PYTHONBIN} ./viewcvs-install.pkgsrc)

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
