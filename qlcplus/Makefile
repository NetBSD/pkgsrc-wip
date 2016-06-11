# $NetBSD$

DISTNAME=	QLC+-4.10.4
PKGNAME=	${DISTNAME:S/QLC+/qlcplus/}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=mcallegari/}
GITHUB_TAG=	${DISTNAME:S/-/_/}

WRKSRC=		${WRKDIR}/qlcplus-QLC-_${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qlcplus.org/
COMMENT=	Q Light Controller Plus
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

do-configure:
	${RUN} cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${QTDIR}/bin/qmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
