# $NetBSD$

DISTNAME=	console-setup_1.188
PKGNAME=	bdf2psf-1.188
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/c/console-setup/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://packages.debian.org/sid/bdf2psf
COMMENT=	Convert a BDF font to PSF format for the Linux console
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/console-setup-1.188

NO_BUILD=	yes

REPLACE_PERL=	Fonts/bdf2psf

SHAREDIR=	${PREFIX}/share/${PKGBASE}

AUTO_MKDIRS=	yes
INSTALLATION_DIRS+= bin ${PKGMANDIR}/man1 ${SHAREDIR}/fontsets

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Fonts/bdf2psf ${DESTDIR}${PREFIX}/bin
	${RUN}${INSTALL_MAN} ${WRKSRC}/man/bdf2psf.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RUN}${INSTALL_DATA} ${WRKSRC}/Fonts/standard.equivalents \
		${DESTDIR}${SHAREDIR}
	${RUN}${INSTALL_DATA} ${WRKSRC}/Fonts/fontsets/* \
		${DESTDIR}${SHAREDIR}/fontsets

.include "../../mk/bsd.pkg.mk"
