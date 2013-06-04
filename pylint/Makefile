# $NetBSD: Makefile,v 1.11 2013/06/04 07:45:24 thomasklausner Exp $

VERSION=	0.22.0
DISTNAME=	pylint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://ftp.logilab.org/pub/pylint/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.logilab.org/project/pylint
COMMENT=	Python code static checker
LICENSE=    	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

DOCDIR= ${PREFIX}/share/doc/pylint
INSTALLATION_DIRS=  ${DOCDIR} ${PKGMANDIR}/man1

#USE_LANGUAGES=	# none

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../devel/py-logilab-astng/buildlink3.mk"
.include "../../devel/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
