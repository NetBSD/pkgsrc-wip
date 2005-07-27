# $NetBSD: Makefile,v 1.2 2005/07/27 16:29:07 thomasklausner Exp $
#

DISTNAME=		shtoom-0.2
PKGNAME=		${PYPKGPREFIX}-shtoom-0.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=shtoom/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://shtoom.sourceforge.net/
COMMENT=		Software VoIP telephony in Python

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/shtoom/ui/gnomeui/shtoom.glade \
		${PREFIX}/${PYSITELIB}/shtoom/ui/gnomeui/shtoom.glade

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
