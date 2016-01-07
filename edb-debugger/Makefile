# $NetBSD$

DISTNAME=	debugger-0.9.20
PKGNAME=	edb-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.codef00.com/downloads/
EXTRACT_SUFX=	.tgz

WRKSRC=		${WRKDIR}/debugger

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codef00.com/projects#debugger
COMMENT=	Cross platform x86/x86-64 debugger
LICENSE=	gnu-gpl-v2

do-configure:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake -makefile DEFAULT_PLUGIN_PATH="${PREFIX}/lib/${PKGBASE}/"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
