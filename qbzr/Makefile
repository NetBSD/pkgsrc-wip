# $NetBSD: Makefile,v 1.1.1.1 2011/11/22 08:50:50 ddeus Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/0.21/${VER}/+download/
VER=		0.21.1

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

WRKSRC=		${WRKDIR}/qbzr

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25

.include "../../wip/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
