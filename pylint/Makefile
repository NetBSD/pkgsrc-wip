# $NetBSD: Makefile,v 1.9 2011/01/18 08:25:34 jihbed Exp $
#

VERSION=	0.22.0
DISTNAME=	pylint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://ftp.logilab.org/pub/pylint/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.logilab.org/project/pylint
COMMENT=	Python code static checker
LICENSE=    	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DOCDIR= ${PREFIX}/share/doc/pylint
INSTALLATION_DIRS=  ${DOCDIR} ${PKGMANDIR}/man1

#USE_LANGUAGES=	# none

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../devel/py-logilab-astng/buildlink3.mk"
.include "../../devel/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
