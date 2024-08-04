# $NetBSD$

PKGNAME=	d2-0.6.6
DISTNAME=	d2-${GITHUB_TAG}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=terrastruct/}
GITHUB_PROJECT=	d2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://d2lang.com/
COMMENT=	Modern diagram scripting language that turns text to diagrams
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN+=	-ldflags "-X oss.terrastruct.com/d2/lib/version.Version=v${PKGVERSION}"
GO_BUILD_PATTERN+=	./

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/d2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ci/release/template/man/d2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
