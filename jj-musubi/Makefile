# $NetBSD$

DISTNAME=	jj-musubi-0.47.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.serpentine.com/software/jj-musubi
COMMENT=	Keep jj repos in sync across your machines, live
LICENSE=	apache-2.0

DEPENDS+=	jj>=0:../../devel/jj

USE_LANGUAGES=	c
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin share/docs/jj-musubi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/musubi ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/docs && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/docs/jj-musubi

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
