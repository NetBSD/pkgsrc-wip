# $NetBSD: Makefile,v 1.2 2010/04/19 13:24:34 jihbed Exp $
#

DISTNAME=	pylint-0.20.0
PKGNAME=	${PYPKGPREFIX}-logilab-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/pylint/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/Project/name/pylint
COMMENT=	Python code static checker
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-astng>=0.20.0:../../wip/py-logilab-astng

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

CONFLICTS=		pylint-[0-9]*

DOCDIR=	${PREFIX}/share/doc/py-logilab-lint

INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
