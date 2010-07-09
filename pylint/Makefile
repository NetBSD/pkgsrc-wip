# $NetBSD: Makefile,v 1.6 2010/07/09 19:06:50 jihbed Exp $
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

DOCDIR=	${PREFIX}/share/doc/pylint

INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
