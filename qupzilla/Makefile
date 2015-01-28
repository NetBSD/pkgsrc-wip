# $NetBSD: Makefile,v 1.10 2015/01/28 15:19:52 nros Exp $

DISTNAME=	QupZilla-1.8.6
PKGNAME=	${DISTNAME:tl}

CATEGORIES=	www
MASTER_SITES=	https://github.com/QupZilla/qupzilla/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qupzilla.com/
COMMENT=	Crossplatform QTWebkit based web browser
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
MAKE_ENV+=	QUPZILLA_PREFIX=${PREFIX}
MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	${PKGSRC_ENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

INSTALLATION_DIRS+= share/zsh/site-functions
post-install:
	${INSTALL_DATA} ${WRKSRC}/linux/completion/_qupzilla \
		${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "options.mk"

.if ${OPSYS} == "OpenBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Haiku"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
