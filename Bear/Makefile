# $NetBSD: Makefile,v 1.2 2015/01/06 19:18:36 jonthn Exp $

DISTNAME=	Bear-1.4.3
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/rizsotto/Bear/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/rizsotto/Bear
COMMENT=	Bear is a tool to generate compilation database
LICENSE=	gnu-gpl-v3

EGDIR=		${PREFIX}/share/examples/bear
INSTALLATION_DIRS=	${EGDIR}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	${EGDIR}
CONF_FILES=	${EGDIR}/bear.conf ${PKG_SYSCONFDIR}/bear.conf

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=   LIBEXT=dylib
.else
PLIST_SUBST+=   LIBEXT=so
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/bear.conf ${DESTDIR}${EGDIR}

.include "../../devel/libconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
