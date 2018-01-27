# $NetBSD$

DISTNAME=	grc-1.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=garabik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/garabik/grc/
COMMENT=	Generic colouriser
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	share/grc share/examples/grc bin ${PKGMANDIR}/man1
CONF_FILES+=		${PREFIX}/share/examples/grc/grc.conf ${PKG_SYSCONFDIR}/grc.conf

REPLACE_PYTHON=	grc grcat

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-build
SUBST_SED.path=		-e "s,/usr/local,${PREFIX},"
SUBST_FILES.path=	grcat grcat.1
SUBST_MESSAGE.path=	Fixing path to config files.

do-build:

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} conf.* ${DESTDIR}${PREFIX}/share/grc && \
		${INSTALL_DATA} grc.conf ${DESTDIR}${PREFIX}/share/examples/grc && \
		${INSTALL_SCRIPT} grc grcat ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_DATA} grc.1 grcat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
