# $NetBSD$

DISTNAME=	mipscope-0.3.3
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=MipScope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mipscope.cs.brown.edu/
COMMENT=	MIPS Learning Environment
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_ENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake PREFIX=${PREFIX} -o Makefile

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
