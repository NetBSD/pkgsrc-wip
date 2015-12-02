# $NetBSD$

DISTNAME=	lumina-i18n-0.8.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=pcbsd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}-Release

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lumina-desktop.org/
COMMENT=	i18n files for the Lumina Desktop Environment
LICENSE=	modified-bsd

NO_BUILD=	yes

LUMINA_I18N_DIR=	${PREFIX}/share/Lumina-DE/i18n

USE_TOOLS+=	tar

post-extract:
	${RUN} cd ${WRKSRC}/dist && tar xf lumina-i18n.txz

do-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${LUMINA_I18N_DIR}
	${RUN} ${INSTALL_DATA} ${WRKSRC}/dist/lumina*.qm ${DESTDIR}${LUMINA_I18N_DIR}

.include "../../mk/bsd.pkg.mk"
