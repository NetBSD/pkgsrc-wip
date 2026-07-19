# $NetBSD: Makefile,v 1.8 2012/09/24 16:56:41 asau Exp $

DISTNAME=		axel-2.17.14
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=axel-download-accelerator/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		ismael@iodev.co.uk
HOMEPAGE=		https://github.com/axel-download-accelerator/axel
COMMENT=		HTTP/FTP download accelerator
LICENSE=		gnu-gpl-v2

.include "options.mk"

USE_TOOLS=		pkg-config
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/examples/axel
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/axelrc.example ${PKG_SYSCONFDIR}/axelrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/axelrc.example ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
