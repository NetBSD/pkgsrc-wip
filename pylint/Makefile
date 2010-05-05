# $NetBSD: Makefile,v 1.5 2010/05/05 09:40:46 jihbed Exp $
#

VERS=					0.20.0
DISTNAME=			pylint-${VERS}
PKGREVISION=    		1
CATEGORIES=			devel
MASTER_SITES=		http://pypi.python.org/packages/source/p/pylint/

MAINTAINER=			helgoman@users.sourceforge.net
HOMEPAGE=			http://www.logilab.org/project/pylint
COMMENT=			Python code static checker
LICENSE=				gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-astng>=0.20.0:../../wip/py-logilab-astng

PKG_DESTDIR_SUPPORT=		user-destdir

DOCDIR=	${PREFIX}/share/doc/pylint

INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
