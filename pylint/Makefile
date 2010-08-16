# $NetBSD: Makefile,v 1.7 2010/08/16 10:15:47 jihbed Exp $
#

VERS=		0.21.1
DISTNAME=	pylint-${VERS}
PKGREVISION=    		1
CATEGORIES=			devel
MASTER_SITES=	http://ftp.logilab.org/pub/pylint/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.logilab.org/project/pylint
COMMENT=	Python code static checker
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-astng>=0.20.0:../../wip/py-logilab-astng

PKG_DESTDIR_SUPPORT=		user-destdir
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

DOCDIR=	${PREFIX}/share/doc/pylint

INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1

post-extract:
	${MV} ${WRKSRC}/bin/epylint ${WRKSRC}/bin/epylint${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pylint ${WRKSRC}/bin/pylint${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pylint-gui ${WRKSRC}/bin/pylint-gui${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyreverse ${WRKSRC}/bin/pyreverse${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/symilar ${WRKSRC}/bin/symilar${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
