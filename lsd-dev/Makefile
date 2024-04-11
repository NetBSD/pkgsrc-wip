# $NetBSD: Makefile,v 1.16 2024/03/27 09:52:01 pin Exp $

DISTNAME=	lsd-1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lsd-rs/}
GITHUB_TAG=	ee2d12bb151fe79f325a82b5849147c6dd5cdfaa

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/lsd-rs/lsd/
COMMENT=	The next gen ls command
LICENSE=	apache-2.0

TOOL_DEPENDS+=	go-md2man-[0-9]*:../../textproc/go-md2man

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1


# Use go-md2man to generate manpages and install them
post-install:
	go-md2man < ${WRKSRC}/doc/lsd.md > ${WRKSRC}/doc/lsd.1
	${INSTALL_MAN} ${WRKSRC}/doc/lsd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
