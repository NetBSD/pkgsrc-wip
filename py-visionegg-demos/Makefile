# $NetBSD: Makefile,v 1.2 2004/05/10 00:44:42 blef Exp $
#

DISTNAME=		visionegg-0.9.9-demo
PKGNAME=		${PYPKGPREFIX}-visionegg-demo-0.9.9
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Demonstration programs for py-visionegg

USE_BUILDLINK3=		yes
NO_BUILD=		# defined
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
MESSAGE_SUBST+=		PY_VE_DIR=${PY_VE_DEMO_DIR}

PY_VE_DEMO_DIR=		${PREFIX}/share/VisionEgg-${PYVERSSUFFIX}/demo

do-install:
	${INSTALL_DATA_DIR} ${PY_VE_DEMO_DIR}
	cd ${WRKSRC}/demo && ${PAX} -rw -pe * ${PY_VE_DEMO_DIR}

.include "../../wip/py-visionegg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
